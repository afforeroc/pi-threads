# Calcular el número Pi con hilos (pthread) en C

# Requerimientos del sistema
* GCC version: `gcc (Ubuntu 8.2.0-7ubuntu1) 8.2.0`

## Pasos
* Compilar: `gcc pi-threads.c -pthread -o pi-threads`
* Ejecutar: `./pi-threads`

## Ejemplo de salida
<pre>
Calculo de Pi con hilos
hilos = 16, tiempo = 3 seg
parcialPi[0] = 3.14159264558932393996
parcialPi[1] = 0.00000000400000000009
parcialPi[2] = 0.00000000133333333258
parcialPi[3] = 0.00000000000000000000
parcialPi[4] = 0.00000000000000000000
parcialPi[5] = 0.00000000000000000000
parcialPi[6] = 0.00000000000000000000
parcialPi[7] = 0.00000000000000000000
parcialPi[8] = 0.00000000000000000000
parcialPi[9] = 0.00000000000000000000
parcialPi[10] = 0.00000000000000000000
parcialPi[11] = 0.00000000000000000000
parcialPi[12] = 0.00000000000000000000
parcialPi[13] = 0.00000000000000000000
parcialPi[14] = 0.00000000000000000000
parcialPi[15] = 0.00000000000000000000
Pi = 3.14159265092265727048
</pre>

## Tiempos de ejecución

### Especificaciones del computador utilizado
<pre>
Sistema operativo: Ubuntu 18.10
Procesador: Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz
Memoria: 11GiB
</pre>

### Hilos vs Tiempo 
<pre>
Hilos   Tiempo[seg]
1       10
2       5
4       3
8       3
16      3
</pre>