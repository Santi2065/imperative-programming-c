   int * p = malloc(n * sizeof(int));
   int * q = malloc(n * sizeof(int));
   /* llenamos y usamos el vector */
   //   ...
   //   ...
   
   // Ya no los necesitamos, podemos liberar ambos vectores
   free(q);  
   free(p);  
