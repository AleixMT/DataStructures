import java.util.ArrayList;
import java.util.List;

public class Node<T extends Comparable<T>> {

    private List<Edge> edges;
    private T t;

    public Node(T t)
    {
        this.t = t;
        edges = new ArrayList<>();
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public void setEdges(List<Edge> edges) {
        this.edges = edges;
    }

    public T getT() {
        return t;
    }

    public void setT(T t) {
        this.t = t;
    }
}
