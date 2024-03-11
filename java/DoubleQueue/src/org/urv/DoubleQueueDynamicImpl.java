package org.urv;

public class DoubleQueueDynamicImpl<T> implements DoubleQueue<T> {

    private Node<T> primer;

    public DoubleQueueDynamicImpl() {
        this.primer = null;
    }

    @Override
    public void addTop(T t) {
        Node<T> newNode = new Node<>(t);
        newNode.next = this.primer;
        newNode.previous = null;
        this.primer.previous = newNode;
        this.primer = newNode;
    }

    private Node<T> getBottomNode()
    {
        Node<T> aux = this.primer;
        while (aux.next != null)
        {
            aux = aux.next;
        }
        // Aux is the last node of the list in here
        return aux;
    }

    @Override
    public void addBottom(T t) {
        Node<T> last = this.getBottomNode();

        Node<T> newNode = new Node<>(t);
        newNode.previous = last;
        newNode.next = null;

        last.next = newNode;
    }

    @Override
    public T popTop() throws Exception {
        if (this.esBuida())
        {
            throw new Exception("La lista esta vacia");
        }

        if (this.primer.next != null)
        {
            Node<T> aux = this.primer;
            this.primer.next.previous = null;
            this.primer = this.primer.next;
            return aux.value;
        }

        // Implicitly there is only one element
        //Guard clauses
        Node<T> aux = this.primer;
        this.primer = null;
        return aux.value;
    }

    private boolean esBuida()
    {
        return this.primer == null;
    }

    @Override
    public T popBottom() throws Exception {
        if (this.esBuida())
        {
            throw new Exception("La lista esta vacia");
        }

        // More than one element
        if (this.primer.next != null)
        {
            Node<T> last = this.getBottomNode();
            last.previous.next = null;
            return last.value;
        }

        Node<T> aux = this.primer;
        this.primer = null;
        return aux.value;
    }

    @Override
    public T top() {
        return this.primer.value;
    }

    @Override
    public T bottom() {
        return this.getBottomNode().value;
    }
}
