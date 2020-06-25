//
// Created by Sergi Vives on 15/4/20.
//

#include "skiplist.h"

/*
 * Reservem la zona de mem per a la skip list i el seu primer node apuntador
 */
int Crear(Skip_list **sl)
{
    *sl = (Skip_list*) malloc(sizeof(Skip_list));
    if (*sl == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut reservar memoria per a la ED de la skiplist\n");
        return ERROR_CREAR;  // Abortem la resta de la funció
    }

    // Inicialitzem dades
    // El node master no apunta a Null, sinó que opunta a un apuntador de Nodes
    // Sera un node "buit"
    (**sl).top_left_node = (Node*) malloc(sizeof(Node));

    // Per a poder fer servir el node apuntador sense tenir problemes
    (**sl).top_left_node->v = INT_MIN;

    return EXIT;
}

/*
 * Recorre la llista i va destruint tots els nodes
 */
int Destruir(Skip_list *sl)
{
    if (sl == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut destruir perque la llista no existeix\n");
        return ERROR_DESTRUIR;  // Abortem la resta de la funció
    }

    // Necessitarem un node temporal per eliminar verticalment, sino ens menjarem un nullpointer a lultim pis
    Node * node_seguent_vertical_temporal;
    // el propi apuntador de la llista ens fara de node iterador, igual que passa en horitzontal
    // mentres l'apuntador sigui NULL itera
    while (sl->top_left_node != NULL)
    {
        // Carreguem el primer node valid daquest nivell
        Node * node_seguent_horitzontal = sl->top_left_node->right;
        // L'altre es un temporal que farem servir per iterar
        // Podriem ferho amb un sol apuntador pero a lultim node ens menjariem un nullpointer
        Node * node_seguent_horitzontal_temporal;
        while (node_seguent_horitzontal != NULL)
        {
            // Fem que node temporal seguent apunti al mateix sobre el que estem
            node_seguent_horitzontal_temporal = node_seguent_horitzontal;
            // fem que node seguent passi a apuntar al node de la dreta (podria ser NULL)
            node_seguent_horitzontal = node_seguent_horitzontal->right;
            // node temporal ara apunta a un node que no es NULL per tant ha de poder ser alliberat
            free(node_seguent_horitzontal_temporal);

            /*
             * Ara passem a evaluar si el node seguent es null o no
             * Si no ho es seguirem iterant i alliberant nodes.
             * Sino sortirem del while
             */

        }
        // Aqui hem de fer el mateix pero en vertical.
        // Ara hem de pensar que tenim una filera de nodes normals buida, i el apuntador encara hi es.
        // movem l'apuntador al node vertical seguent i guardem la ref al temporal per a alliberarla despres
        node_seguent_vertical_temporal = sl->top_left_node;
        // Passem al sguent node cap avall (podria ser un null pointer i llavors acabariem el while)
        sl->top_left_node = sl->top_left_node->down;
        // alliberem el node temporal
        free(node_seguent_vertical_temporal);

        /*
         * Ara passem a evaluar si el node seguent en verticla es null o no
         * Si no ho es seguirem iterant i alliberant nodes.
         * Sino sortirem del while
         */
    }

    // Finalment destruim l'estructura
    free(sl);
    return EXIT;
}

/*
 * Compta els elements de lultim pis i retorna aquest nombre
 */
int Longitud(Skip_list sl, unsigned int *lon)
{
    // Per a comptar sense massa complicació hem d'anar a l'últim pis i veure quants elements hi ha
    Node * node_apuntador_primer_pis = sl.top_left_node;

    while (node_apuntador_primer_pis->down != NULL)
    {
        node_apuntador_primer_pis = node_apuntador_primer_pis->down;
    }
    // En aquest punt, node apuntador primer pis apunta a l'apuntador que té "down" = NULL, per tant ha de ser el primer pis

    // Mentre no arribem a un node que té right com a NULL (ultim node a la columna de la dreta)
    *lon = 0;

    // No comptem el bloc d'apuntadors
    node_apuntador_primer_pis = node_apuntador_primer_pis->right;
    while (node_apuntador_primer_pis != NULL)
    {
        (*lon)++;
        node_apuntador_primer_pis = node_apuntador_primer_pis->right;
    }
    return EXIT;

}


/*
 * Returns the height of the skip list
 */
unsigned int height(Skip_list sl)
{
    // Per a comptar sense massa complicació hem d'anar a l'últim pis i veure quants elements hi ha
    Node * node_apuntador_primer_pis = sl.top_left_node;
    unsigned int num_floors = 1;
    while (node_apuntador_primer_pis->down != NULL)
    {
        node_apuntador_primer_pis = node_apuntador_primer_pis->down;
        num_floors++;
    }
    return num_floors;
}

/*
 * Cerca de forma interna el node a la posició amb més altura tal que el seu
 * valor es igual a elem. Retorna aquest node en forma de punter. Si no el troba
 * retorna null.
 * Search(key)
    p = top-left node in S
    while (p.below != null) do        //Scan down
        p = p.below
        while (p.right != null) do      //Scan forward
            if (p.v == elem) return p;
            p = p.next
    return NULL
 */
Node * Cercar(Skip_list sl, int elem)
{
    Node * node_iterador_vertical = malloc(sizeof(Node));
    // Per no embrutar i entrar directament amb el while sense un loop unrolling
    node_iterador_vertical->down = sl.top_left_node;

    Node * node_iterador_horitzontal = malloc(sizeof(Node));

    while (node_iterador_vertical->down != NULL)
    {
        // Ens movem cap al nivell inferior
        node_iterador_vertical = node_iterador_vertical->down;
        node_iterador_horitzontal = node_iterador_vertical;
        while (node_iterador_horitzontal->right != NULL)
        {
            // En la primera iteració sempre estem a un node apuntador per tant sempre hem de fer una iteració
            node_iterador_horitzontal = node_iterador_horitzontal->right;
            if (node_iterador_horitzontal->v == elem) return node_iterador_horitzontal;
        }
    }
    return NULL;
}

/*
 * Cerca de forma interna i òptima el node amb menys altura de tota la skip list tal que
 * aquest node tingui el valor més gran possible pero que sigui menor o igual al paràmetre
 * elem. Es a dir, el nou element sempre s'ha d'afegir a la dreta del node retornat per aquesta
 * fucnió
 *
 * Utilitzat per la funció afegir.
 * Search(key)
    p = top-left node in S
    while (p.below != null) do        //Scan down
        p = p.below
        while (key >= p.next) do      //Scan forward
            p = p.next
    return p
 */
Node * CercaAfegiment(Skip_list sl, int elem)
{
    Node * node_iterador = malloc(sizeof(Node));
    // Per no embrutar i entrar directament amb el while sense un loop unrolling
    node_iterador->down = sl.top_left_node;


    while (node_iterador->down != NULL)
    {
        // Ens movem cap al nivell inferior
        node_iterador = node_iterador->down;
        while (node_iterador->right != NULL && node_iterador->right->v <= elem)
        {
            // En la primera iteració sempre estem a un node apuntador per tant sempre hem de fer una iteració
            node_iterador = node_iterador->right;
        }
    }
    return node_iterador;
}

Node * insertAfter(Node * node_previ, int elem)
{
    // Creem el nou node
    Node * node_per_afegir = (Node *) malloc(sizeof(Node));

    node_per_afegir->v = elem;

    // Fem apuntar el nou node a on apunta el node previ
    node_per_afegir->right = node_previ->right;  // Podriem estar fentlo apuntar a NULL
    if (node_per_afegir->right != NULL)
    {
        // Fem que el node a la dreta del node previ apunti al nou node
        node_per_afegir->right->left = node_per_afegir;
    }  // Sino no cal fer apuntar a ningu perque l'element de la dreta es NULL
    // Fem apuntar el nou node al node previ
    node_per_afegir->left = node_previ;
    // Fem que el node previ apunti al nou node
    node_previ->right = node_per_afegir;

    return node_per_afegir;
}

/*
 * Insert(key)
    p = Search(key)
    q = null
    i = 1
    repeat
        i = i + 1                   //Height of tower for new element
        if i >= h
            h = h + 1
            createNewLevel()        //Creates new linked list level
        while (p.above == null)
            p = p.prev              //Scan backwards until you can go up
        p = p.above
        q = insertAfter(key, p)     //Insert our key after position p
    until CoinFlip() == 'Tails'
    n = n + 1
    return q
 */
int Inserir(Skip_list *sl, int elem)
{
    if (sl == NULL)
    {
        fprintf(stderr, "ERROR: No s'ha pogut inserir perque la llista no existeix\n");
        return ERROR_LLISTA_INEXISTENT;  // Abortem la resta de la funció
    }

    // Busquem posició més baixa per afegir nou node
    Node * node_iterador = CercaAfegiment(*sl, elem);
    // Afegim el nou node i el retornem per si hem de seguir apilant pisos
    Node * node_afegit = insertAfter(node_iterador, elem);
    // Node iterador apunta al node afegit.
    node_iterador = node_afegit;

    // Tirem una moneda
    bool coin = rand() % 2 == 0;
    fflush(stdout);

    // Entrem si la moneda surt que si, sino ja hauriem acabat, ja que l'element en si ja s'ha afegit
    while (coin)
    {

        fflush(stdout);
        // Busquem l'element previ del nou nivell. Sempre entrarem almenys 1 cop
        // perque node_iterador = node_afegit i node_afegit->top = NULL
        //
        while (node_iterador != NULL && node_iterador->top == NULL)
        {
            node_iterador = node_iterador->left;
        }
        fflush(stdout);

        /*
         *En aquest punt o bé node_iterador es NULL per tant hem d'afegir un nou pis
         * o bé node_iterador es un node que té disponible un pis superior a on afegirem
         * el nostre node.
         */

        // Hem arribat al bloc d'apuntadors, per tant cal afegir un nou pis sencer i actualitzar
        if (node_iterador == NULL)
        {
            // Reservem un nou Node (un apuntador)
            node_iterador = (Node *) malloc(sizeof(Node));
            // Connectem el nou node a la ED
            node_iterador->down = sl->top_left_node;
            // Conncetem la ED al nou node
            sl->top_left_node->top = node_iterador;
            // Actualitzem l'apuntador principal
            sl->top_left_node = node_iterador;
            // Afegim el valor minim d'enter al apuntador
            sl->top_left_node->v = INT_MIN;

        }
        else  // Hem trobat un node per a "pujar"
        {
            // Ja hem trobat el node on afegirem el nou pis
            node_iterador = node_iterador->top;
        }

        /*
         * En aquest punt node_iterador apunta al node a l'esquerra del node que hem
         * d'afegir.
         */


        node_iterador = insertAfter(node_iterador, elem);

        /*
         * Aqui tenim node_afegit que apunta al node afegit a l'anterior iteració i
         * node_iterador que apunta al node afegit en aquesta iteració.
         * Cal conectar-los.
         */

        node_iterador->down = node_afegit;
        node_afegit->top = node_iterador;

        /*
         * Actualitzem punters per a la següent iteració.
         */

        node_afegit = node_iterador;
        // Tornem a llençar la moneda
        coin = ignuin(1, 1000000) % 2 == 0;
    }
    return EXIT;
}

void Recorrer(Skip_list sl)
{
    printf("Contingut de la llista: \n");
    // Per a comptar sense hòsties hem d'anar a l'últim pis i veure quants elements hi ha
    Node * node_apuntador_primer_pis = sl.top_left_node;

    while (node_apuntador_primer_pis->down != NULL)
    {
        node_apuntador_primer_pis = node_apuntador_primer_pis->down;
    }
    // En aquest punt, node apuntador primer pis apunta a l'apuntador que té "down" = NULL, per tant ha de ser el primer pis

    // Mentre no arribem a un node que té right com a NULL (ultim node a la columna de la dreta)
    while (node_apuntador_primer_pis->right != NULL)
    {
        node_apuntador_primer_pis = node_apuntador_primer_pis->right;
        printf("%i ", node_apuntador_primer_pis->v);
    }
    printf("\n");
}


int Esborrar (Skip_list *sl, int elem)
{
    Node * node_iterador_vertical = malloc(sizeof(Node));
    Node * node_iterador_horitzontal = malloc(sizeof(Node));
    bool trobat = false;
    node_iterador_vertical = sl->top_left_node;

    while (node_iterador_vertical != NULL && !trobat)
    {
        node_iterador_horitzontal = node_iterador_vertical;
        while (node_iterador_horitzontal != NULL)
        {
            if (node_iterador_horitzontal->v == elem)
            {
                trobat = true;
                break;
            }
            node_iterador_horitzontal = node_iterador_horitzontal->right;
        }
        // Ens movem cap al nivell inferior
        node_iterador_vertical = node_iterador_vertical->down;
    }

    /*
     * En aquest punt node_iterador_horitzontal apunta al node a més altura que
     * conté l'element a eliminar. No cal eliminar els punters verticals ja que
     * seran eliminats.
     */

    Node * node_iterador_horitzontal_previ = node_iterador_horitzontal;
    node_iterador_horitzontal = node_iterador_horitzontal->down;

    while (node_iterador_horitzontal != NULL)
    {
        // Connectem node de l'esquerra al que tenim a la dreta
        node_iterador_horitzontal_previ->left->right = node_iterador_horitzontal_previ->right;

        // Connectem node de la dreta al que tenim a l'esquerra si es un node i no NULL
        if (node_iterador_horitzontal_previ->right != NULL)
        {
            node_iterador_horitzontal_previ->right->left = node_iterador_horitzontal_previ->left;
        }

        // Alliberem memoria
        free(node_iterador_horitzontal_previ);

        // Guardem referencia al seguent node
        node_iterador_horitzontal_previ = node_iterador_horitzontal;
        node_iterador_horitzontal = node_iterador_horitzontal->down;
    }

    // Loop unrolling de la ultima iteració
    // Connectem node de l'esquerra al que tenim a la dreta
    node_iterador_horitzontal_previ->left->right = node_iterador_horitzontal_previ->right;

    // Connectem node de la dreta al que tenim a l'esquerra si es un node i no NULL
    if (node_iterador_horitzontal_previ->right != NULL)
    {
        node_iterador_horitzontal_previ->right->left = node_iterador_horitzontal_previ->left;
    }

    // Alliberem memoria
    free(node_iterador_horitzontal_previ);
    return EXIT;
}

int Buscar(Skip_list sl, int elem, bool *trobat)
{
    Node * node_iterador_vertical = malloc(sizeof(Node));
    Node * node_iterador_horitzontal = malloc(sizeof(Node));
    node_iterador_vertical = sl.top_left_node;

    while (node_iterador_vertical != NULL)
    {
        node_iterador_horitzontal = node_iterador_vertical;
        while (node_iterador_horitzontal != NULL)
        {
            if (node_iterador_horitzontal->v == elem)
            {
                *trobat = true;
                return EXIT;
            }
            node_iterador_horitzontal = node_iterador_horitzontal->right;
        }
        // Ens movem cap al nivell inferior
        node_iterador_vertical = node_iterador_vertical->down;
    }
    *trobat = false;
    return EXIT;

}

int Cost_Buscar(Skip_list sl, int elem, int *cost);

void toString(Skip_list sl)
{
    Node * node_iterador_vertical = malloc(sizeof(Node));
    Node * node_iterador_horitzontal = malloc(sizeof(Node));
    node_iterador_vertical = sl.top_left_node;

    while (node_iterador_vertical != NULL)
    {
        node_iterador_horitzontal = node_iterador_vertical;
        printf("\n");
        while (node_iterador_horitzontal != NULL)
        {
            // En la primera iteració sempre estem a un node apuntador per tant sempre hem de fer una iteració
            printf("%i --> ", node_iterador_horitzontal->v);
            node_iterador_horitzontal = node_iterador_horitzontal->right;
        }
        // Ens movem cap al nivell inferior
        node_iterador_vertical = node_iterador_vertical->down;
    }
}

void toMatrix(Skip_list sl)
{
    unsigned int longitud, altura = height(sl), i, j = 0;
    Longitud(sl, &longitud);
    longitud++;  // Per tenir en compte el bloc d'apuntadors
    int * matrix = (int *) malloc(sizeof(int) * longitud * altura);
    for (int i = 0; i < longitud * altura; i++)
    {
        matrix[i] = 0;
    }

    Node * node_iterador_vertical = malloc(sizeof(Node));
    Node * node_iterador_horitzontal = malloc(sizeof(Node));
    node_iterador_vertical = sl.top_left_node;

    while (node_iterador_vertical->down != NULL)
    {
        // Ens movem cap al nivell inferior
        node_iterador_vertical = node_iterador_vertical->down;
    }
    node_iterador_horitzontal = node_iterador_vertical;  // Els dos apunten al node de la cantonada inferior esquerre

    while (node_iterador_horitzontal != NULL)
    {
        i = altura - 1;
        node_iterador_vertical = node_iterador_horitzontal;
        while (node_iterador_vertical != NULL)
        {
            matrix[i * longitud + j] = node_iterador_vertical->v;
            node_iterador_vertical = node_iterador_vertical->top;
            i--;
        }
        // Ens movem cap al nivell inferior
        node_iterador_horitzontal = node_iterador_horitzontal->right;
        j++;
    }

    for (int i = 0; i < altura; i++)
    {
        printf("\n");
        for (int j = 0; j < longitud; j++)
        {
            printf("%i", matrix[i * longitud + j]);
            if (j != longitud - 1)
            {
                printf(" --> ");
            }
        }
    }

}
