import java.util.ArrayList;
import java.util.List;

public class Edge<T extends Comparable<T>, E extends Comparable<E>> implements Comparable<E>{

    private List<Node<T, E>> nodes;
    private E e;

    public Edge(E e)
    {
        this.e = e;
        nodes = new ArrayList<>();
    }

    public List<Node<T, E>> getNodes() {
        return nodes;
    }

    public void setNodes(List<Node<T, E>> nodes) {
        this.nodes = nodes;
    }

    public E getE() {
        return e;
    }

    public void setE(E e) {
        this.e = e;
    }

    @Override
    public int compareTo(E o) {
        return e.compareTo(o);
    }
}
