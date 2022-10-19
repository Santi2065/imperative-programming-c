struct art {
    int code;
   double price;
};

struct art * newArt(int c, double r) {
    struct art p;
    p.code = c;
    p.price = r;
    return &p;
}
