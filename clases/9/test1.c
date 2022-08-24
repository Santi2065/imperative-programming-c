void
esMultiplo(int n,int m)
{
   while(n>=m)
      n-=m;
   printf("%s es multiplo\n",(n==0)?"Si":"No");
}