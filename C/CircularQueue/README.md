# Ex2

### Tasques realitzades:
* S'ha complert l'especificació basica de la cua circular demanada per l'enunciat.
* S'ha fet un joc de proves extens del funcionament basic al fitxer test_cua.c
* S'ha completat l'algorisme de generació del triangle de pascal. Aquest algorisme accepta com a parametre el nombre de pisos a generar. Sino en genera 10.

### Detalls d'implementació
Igual que a l'exercici anterior cal destacar que s'ha canviat la firma de la funcio crear ja que sino resulta impossible implementar la funcio Destruir() ja que es impossible recuperar l'adreça original creada per la funcio malloc al reservar memòria.
El que s'ha fet es fer que la funció retorni un punter de punters, així podem retornar aquesta adreça.

Al l'algorisme del triangle s'ha inclòs zeros a banda i banda de cada fila per a facilitar la generació del triangle. Aquests no afecten a la forma del triangle en si.

També s'ha inclos la possibilitat de passarli un parametre al l'algorisme del triangle que indica la quantitat de pisos a generar.

##### Comandes per a correr l'algorisme
   - Testing de la llista circular: `make runtest`
   - Triangle de pascal: `make runtriangle`

#### Extra:
* S'han implementat TOTES les operacions i funcionalitat extra en la cua:
    - Invertir elements entre dues posicions donada una cua
    - Redimensionar la cua quan esta plena
    - Fusionar dues cues ordenades.
    - Rutina de comprovació de que una cua esta ordenada (utilitzada a la rutina de fusio)

### Notes: 
* Els errors no aborten el programa i també imprimeixen pel canal d'error. 
* La rutina de comprovació de ordre no retorna codis d'error perque ja es checkegen al entrar i tambe per comoditat, ja que el retorn de la funció hauria d'estar reservat per a la seva propia funcionalitat i per comoditat del programador.
* S'ha inclos un makefile per a facilitar la compilacio i execució de l'algorisme.
