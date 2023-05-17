# Autoevaluación de sintaxis de C

1. ¿Cúal de las siguientes afirmaciones es cierta para el lenguaje C?
     - [ ]   C es un lenguaje de programación interpretado (el programa fuente se traduce a lenguaje máquina cada vez que es ejecutado).
     - [ ]   C es un lenguaje rígido con los tipos de datos, no permitiendo mezclar elementos con tipos de datos diferentes en las expresiones.
     - [ ]   C emula la potencia de los lenguajes tipo ensambador.
     - [ ]   C no diferencia entre mayúsculas y minúsculas.  

2. ¿Cúal de las siguientes es una palabra reservada del lenguaje C?
     - [ ]   CHAR
     - [ ]   INT
     - [ ]   FLOAT
     - [ ]   Ninguna de las anteriores
3. ¿Es obligatorio que aparezca al principio de todos los programas en C una línea donde se incluya la librería stdio.h (Standard input/output)?
     - [ ]   Si, siempre debe de aparecer.
     - [ ]   No es obligatorio, se puede omitir en cualquier programa.
     - [ ]   Sólamente si el programa utiliza las funciones printf y/o scanf, para escribir datos en pantalla y/o leer datos a través del teclado.
     - [ ]   Si lo es si el programa utiliza alguna de las funciones incluida en la librería estándar de E/S (stdio).
4. ¿Cuál es el tamaño que ocupa en memoria central un dato de tipo int?
     - [ ]   1 byte
     - [ ]   2 bytes
     - [ ]   4 bytes
     - [ ]   Depende de la máquina y/o compilador

5. ¿Cuál es el tamaño que ocupa en memoria central un dato de tipo float?
     - [ ]   1 byte
     - [ ]   2 bytes
     - [ ]   4 bytes
     - [ ]   Depende de la máquina y/o compilador
6. ¿Cuál de los siguientes identificadores de tipo no es válido en C?
     - [ ]   signed short int
     - [ ]   unsigned long int
     - [ ]   short float
     - [ ]   unsigned char
7. ¿Cómo se representa en C el tipo de dato real simple precisión?
     - [ ]   single
     - [ ]   long int
     - [ ]   real
     - [ ]   float
8. ¿Cuál de las siguientes constantes de carácter no es válida?
     - [ ]   'a'
     - [ ]   '\n'
     - [ ]   '\103'
     - [ ]   '\y'
9. ¿Cual de las siguientes constantes literales reales es correcta?
     - [ ]   12.3E+0.5
     - [ ]   12.3 E+20
     - [ ]   1E21
     - [ ]   "12.3E+20"
10. ¿De qué tipo de dato es la constante literal PI?
      - [ ]   Entera
      - [ ]   Real simple precisión
      - [ ]   Real doble precisión
      - [ ]   Constante literal no válida
11. ¿Cómo se representan en C las constantes lógicas (o booleanas)?
      - [ ]   0, distinto de cero
      - [ ]   Verdadero, falso
      - [ ]   True, false
      - [ ]   TRUE, FALSE
12. ¿Cuál es el resultado de la expresión 2/3?
      - [ ]   0,666667
      - [ ]   0.666667
      - [ ]   1
      - [ ]   0
13. Si en un compilador de C el tipo entero se representa mediante 2 bytes de memoria, ¿Cuál sería el resultado de la expresión 32000+1000?
      - [ ]   33000
      - [ ]   0
      - [ ]   -32536
      - [ ]   Sintax error: int overflow
14. ¿Cuál es el resultado de la expresión 2%3?
      - [ ]   0
      - [ ]   1
      - [ ]   2
      - [ ]   3
15. ¿Cúal de las siguientes constantes enteras no es válida?
      - [ ]   0xAB
      - [ ]   55UL
      - [ ]   -34L
      - [ ]   FF1
16. ¿Con cuál de las siguientes expresiones se podría obtener el valor real (con los decimales correspondientes) de la división entre dos variables enteras x e y?
      - [ ]   (float) (x/y)
      - [ ]   1.0* x/y
      - [ ]   (float) x/y
      - [ ]   Con todas las anteriores
17. ¿Cuál es el resultado de la expresión a && b?
Nota: los valores asignados a las variables son:
a=1
b=0
      - [ ]   true
      - [ ]   false
      - [ ]   0
      - [ ]   1
18.  Si a, b y c son tres variables enteras, ¿en qué caso la expresión a && b && c devuelve el valor verdadero?
      - [ ]   a=1
    b=-1
    c=0
      - [ ]   a=-1
    b=-1
    c=-1
      - [ ]   a=1
    b=1
    c=0
      - [ ]   a=0
    b=3
    c=4
19.  Determinar qué identificador no es válido
      - [ ]   XMAS11
      - [ ]   xmas11
      - [ ]   x-mas-11
      - [ ]   x_mas_11
20.  Determinar qué identificador es válido
       - [ ]   _11masx
       - [ ]   11masx
       - [ ]   11_mas_x
       - [ ]   x mas 11
21. Determinar qué identificador es válido
      - [ ]   nombre_y_apellido1_y_apellido2
      - [ ]   continue
      - [ ]   año
      - [ ]   nota examen
22. ¿Cuál es el resultado de la siguiente expresión: 3||0?
      - [ ]   Verdadero
      - [ ]   0
      - [ ]   1
      - [ ]   3
23. ¿Cuál es el resultado de la siguiente expresión: 3|0?
      - [ ]   Verdadero
      - [ ]   0
      - [ ]   1
      - [ ]   3
24. ¿Cuál es el resultado de la siguiente expresión: !3?
      - [ ]   Sintax Error
      - [ ]   falso
      - [ ]   0
      - [ ]   1
25. Las variables enteras a y b tienen asignados respectivamente los valores 1 y 2. ¿Qué valores tendrán tras ejecutar la siguiente instrucción: b=a++;?
      - [ ]   a=2
    b=2
      - [ ]   a=1
    b=2
      - [ ]   a=2
    b=1
      - [ ]   Sintax Error
26. Las variables enteras a y b tienen asignados respectivamente los valores 1 y 2. ¿Qué valores tendrán tras ejecutar la siguiente instrucción: b=++a;?
      - [ ]   a=2
    b=2
      - [ ]   a=1
    b=2
      - [ ]   a=2
    b=1
      - [ ]   Sintax Error
27. La variables entera a tiene asignado el valor 5. ¿Qué valor tendrá tras ejecutar la siguiente instrucción: a*=3;?
      - [ ]   a=3
      - [ ]   a=15
      - [ ]   a=53
      - [ ]   Sintax Error
28. ¿Qué sintaxis es válida para leer por teclado un dato entero?
      - [ ]   int n;
    scanf(" %e",n);
      - [ ]   int n;
    scanf(" %d", n);
      - [ ]   int n;
    scanf(" %d, &n);
      - [ ]   int n;
    scanf(" %d",&n);
29. ¿Qué resultado produce en pantalla la siguiente instrucción: printf("\n%5d\n%5d\n%5d",234,1345,6);?
      - [ ]   Pantalla:
            Línea 1: __234
            Línea 2: _ 1345
            Línea 3: ___ 6
      - [ ]   Pantalla:
           Línea 1: 234 1345 6
      - [ ]   Pantalla:
            Línea 1: 234
            Línea 2: 1345
            Línea 3: 6
      - [ ]   Pantalla:
    Línea 1: Sintax Error
30.  ¿Qué resultado produce en pantalla la siguiente instrucción: printf("\n%-5.3s\n%5.3s","Hola","Hola");?
       - [ ]   Pantalla:
            Línea 1: Hol
            Línea 2: ola
       - [ ]   Pantalla:
            Línea 1: Hol
            Línea 2: _ Hol
       - [ ]   Pantalla:
            Línea 1: _Hol
            Línea 2: Hol
       - [ ]   Pantalla:
            Línea 1: Sintax Error
31.  ¿Cuál de las siguientes instrucciones no es correcta sintácticamente para escribir en pantalla el resultado de una expresión real?
          - [ ]   printf("% f",sqrt(5)*2);
          - [ ]   printf("%10.2f",sqrt(5)*2);
          - [ ]   printf("%-10.2f",sqrt(5)*2);
          - [ ]   printf("%.2f",sqrt(5)*2);
32.  ¿Cuál es la instrucción correcta para leer por teclado un dato real en doble precisión?
          - [ ]   scanf(" %f",&x);
          - [ ]   scanf(" %lf",x);
          - [ ]   scanf(" lf",&x);
          - [ ]   scanf(" %lf",&x);
33.  Indicar el resultado de la siguiente instrucción, suponiendo que la variable a es entera y tiene asignado el valor 5:
if (a=10)
printf("a tiene el valor 10");
else printf("a tiene un valor distinto de 10");
       - [ ]   a tiene el valor 10
       - [ ]   a tiene un valor distinto de 10
       - [ ]   a tiene el valor 10 
       - [ ]   a tiene un valor distinto de 10
       - [ ]   Sintax Error
