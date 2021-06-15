public class Node<T extends Comparable<T>> {
    private Node<T> next;
    private T t;

    public Node(Node<T> next, T t) {
        this.next = next;
        this.t = t;
    }

    public Node(T t) {
        this.t = t;
    }

    public Node<T> getNext() {
        return next;
    }

    public T getT() {
        return t;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}
