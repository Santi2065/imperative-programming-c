"""Regenerates the figures shown in the README from the repository itself.

    pip install matplotlib
    python docs/figures/make_figures.py      # run inside the git clone (uses `git log`)
"""
import subprocess
from datetime import date
from pathlib import Path

import matplotlib

matplotlib.use("Agg")
import matplotlib.dates as mdates
import matplotlib.pyplot as plt
from matplotlib import font_manager
from matplotlib.patches import Patch

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
for f in Path("/usr/share/fonts/lm").glob("lm*10-*.otf"):  # Latin Modern, if installed
    font_manager.fontManager.addfont(str(f))
plt.style.use(HERE / "paper.mplstyle")
C = plt.rcParams["axes.prop_cycle"].by_key()["color"]


def save(fig, name):
    fig.savefig(HERE / name, metadata={"Date": None})
    plt.close(fig)


# (folder, label, topic, block). Topics of TP3-TP8 are the titles of the course guides
# (pdfs/TP_0*.pdf, pdfs/*/TP_0*.docx); the others are inferred from the solutions.
FOLDERS = [
    ("guia_1", "TP 1", "First programs, comments, printf", 0),
    ("guia_2", "TP 2", "Data types, expressions, getchar/getint", 0),
    ("guia_3", "TP 3", "Control flow", 0),
    ("guia_4", "TP 4", "Macros and functions", 0),
    ("guia_5", "TP 5", "Functions and the standard library", 0),
    (None, "TP 6", "Arrays, pointers, strings (no folder)", 1),
    ("guia_7", "TP 7", "Advanced programming and the heap", 1),
    ("guia_8", "TP 8", "Structures (struct, union)", 1),
    ("guia_9", "TP 9", "Recursion", 2),
    ("guia_10", "TP 10", "Linked lists, recursively", 2),
    ("guia_11", "TP 11", "Lists with function pointers, ADTs", 2),
    ("TADS", "ADTs", "Exam-style ADTs (bible, synonyms, vector)", 2),
    ("Lab", "Lab", "Lab sessions: bits, random numbers", 0),
    ("clases", "Lectures", "Code written along the lectures", 3),
    ("parciales", "Exams", "Midterm practice (1st and 2nd)", 3),
]
BLOCKS = ["Fundamentals", "Memory and aggregates", "Recursion and data structures", "Lectures and exams"]
COURSE_FILES = ("_test.c", "getnum", "utillist.c")  # tests and helpers handed out by the course


def solutions(folder):
    files = subprocess.run(["git", "ls-files", folder], cwd=ROOT, capture_output=True, text=True).stdout.split("\n")
    return [f for f in files if f.endswith(".c") and not any(k in Path(f).name for k in COURSE_FILES)]


def commit_dates(folder):
    out = subprocess.run(["git", "log", "--format=%ad", "--date=short", "--", folder],
                         cwd=ROOT, capture_output=True, text=True).stdout.split()
    return sorted(date.fromisoformat(d) for d in out)


counts = [len(solutions(f)) if f else 0 for f, *_ in FOLDERS]
print("C source files written per folder:")
for (f, lab, *_), n in zip(FOLDERS, counts):
    print(f"  {lab:9s} {f or '-':10s} {n:3d}")
print(f"  total {sum(counts)}")

# ---- Figure 1: course map, files per guide
fig, ax = plt.subplots(figsize=(7.2, 4.0))
y = range(len(FOLDERS))[::-1]
for yi, (f, lab, topic, b), n in zip(y, FOLDERS, counts):
    ax.barh(yi, n, height=0.62, color=C[b], alpha=0.9 if f else 0.0, edgecolor=C[b], lw=0.6)
    ax.text(max(n, 0) + 0.4, yi, topic, va="center", fontsize=8.5, color="#1a1a1a" if f else "#8c8c8c")
ax.set_yticks(list(y), [lab for _, lab, *_ in FOLDERS])
ax.set_xlabel("C source files written (course tests and helpers excluded)")
ax.set_xlim(0, 40)
ax.tick_params(axis="y", length=0, right=False)
ax.tick_params(top=False)
ax.legend(handles=[Patch(color=C[b], label=name) for b, name in enumerate(BLOCKS)], loc="lower right")
save(fig, "fig1-course-map.svg")

# ---- Figure 2: when each folder was worked on (one dot per commit touching it)
fig, ax = plt.subplots(figsize=(7.2, 3.6))
for yi, (f, lab, topic, b) in zip(y, FOLDERS):
    if not f:
        continue
    d = commit_dates(f)
    ax.plot([d[0], d[-1]], [yi, yi], color=C[b], lw=2.2, alpha=0.35, solid_capstyle="round")
    ax.plot(d, [yi] * len(d), "o", color=C[b], ms=3.6)
ax.set_yticks(list(y), [lab for _, lab, *_ in FOLDERS])
ax.tick_params(axis="y", length=0, right=False)
ax.tick_params(top=False)
ax.xaxis.set_major_locator(mdates.MonthLocator())
ax.xaxis.set_major_formatter(mdates.DateFormatter("%b %Y"))
ax.set_xlim(date(2022, 8, 6), date(2022, 12, 6))
ax.set_xlabel("commit date")
save(fig, "fig2-timeline.svg")
