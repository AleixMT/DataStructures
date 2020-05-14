import java.util.ArrayList;
import java.util.List;

public class Node<T extends Comparable<T>, E extends Comparable<E>> implements Comparable<T> {

    private List<Edge<T, E>> edges;
    private T t;

    public Node(T t)
    {
        this.t = t;
        edges = new ArrayList<>();
    }

    public List<Edge<T, E>> getEdges() {
        return edges;
    }

    public void setEdges(List<Edge<T, E>> edges) {
        this.edges = edges;
    }

    public T getT() {
        return t;
    }

    public void setT(T t) {
        this.t = t;
    }

    @Override
    public int compareTo(T o) {
        return t.compareTo(o);
    }

    @Override
    public String toString() {
        return "Node{" +
                "edges=" + edges +
                ", t=" + t +
                '}';
    }
}
