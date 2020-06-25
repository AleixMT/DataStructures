# Ex1
### Tasques realitzades:
* S'ha complert l'especificació basica de la pila demanada per l'enunciat.
* S'han fet fins a 10 jocs de proves proveits per diferents fitxers amb el nom "input#num.txt". Aquests inclouen el testeig de diferents operacions, incloent les opcionals. Aquestes operacions han de donar 0 per a validar el seu funcionament.
* S'ha implementat la calculadora RPN

### Detalls implementació
Primer de tot cal destacar que s'ha canviat la firma de la funcio Crear(), per a que retorni unpunter
a una pila en lloc d'una pila en si.
Aixo s'ha fet perque sino es IMPOSSIBLE destruir la pila ja que no es pot recuperar la adreça original proveida
per la funció malloc.

També cal dir que la forma de llegir a les calculadores es caracter a caracter ja que treballar amb scanf es massa tosc quan treballem amb dades en diferents formats, de forma que l'algorisme funciona com una màquina d'estats.

Les operacions es poden realitzar afegint el caracter corresponent al fitxer d'entrada tot i que es poden testejar totes fent servir els fitxer de input:
  - Factorial: !
  - Potencia: ^
  - Modul: %
  - Números combinatoris: b
  - Duplicació: r(Repetició)
  - Permutació: p
  - Repetició: r
  - Cicle de tres elements: t
  - Nombre combinatori: b(binomial)
  - Logaritme neperià: l
  - Logaritme de base escollida: L
  - Sinus: u
  - Arcsinus: U
  - Cosinus: o
  - Arcosinus: O
  - Tangent: n
  - Arctangent: N
  - Nombre e: e
  - Nombre pi: m
    
##### Comandes per a correr l'algorisme
   - Calculadora rpn d'enters: `make runrpn`
   - Calculadora de flotants: `make runrpnreals`
   - Testing de pila d'enters: `make runtest` 
   - Testing de pila d'enters: `make runtestreals`

#### Extra:
* S'han implementat operacions extra en la pila "basica": 
    - Factorial 
    - Potencia (De nombre naturals)
    - Modul
    - Numeros combinatoris
* S'han implementat totes les operacions extra de manipulació de la pila a la calculadora RPN:
    - Duplicació
    - Permutació
    - Repetició
    - Cicle de tres elements
* S'ha implementat una calculadora RPN amb nombres reals fent servir el seu propi fitxer de header. Aquest algorisme posseeix tambe 10 fitxers de test. Aquesta inclou les operacions:
    - Retrocompatibilitat amb TOTES les operacions que ja es podien fer a la calculadora RPN amb nombres enters
    - Raons trigonometriques: sinus, cosinus, tangent, arcsinus, arccosinus, arctangent.
    - Reconeixement de nombres irracionals: pi i e.
    - Logaritmes: neperia i de qualsevol base.
    - Potencia de qualsevol argument.




### Notes: 
* Per a la calculadora RPN amb reals s'ha inclos la llibreria math.h. Per a compilar aquest fitxer cal linkejar aquesta llibreria. Això ja es fa al makefile.
* Les dues calculadores tenen els seus propis fitxers de testing. Les operacions al final han de donar 0 per a validar l'algorisme.
* Les calculadores tambe tenen els seus propis codis d'error.
* Els errors normalment aborten el programa i també imprimeixen pel canal d'error.
* S'ha inclos un makefile per a facilitar la compilacio i execució de l'algorisme.


 
