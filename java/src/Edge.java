import java.util.ArrayList;
import java.util.List;

public class Edge<E extends Comparable<E>> {

    private List<Node> nodes;
    private E e;

    public Edge(E e)
    {
        this.e = e;
        nodes = new ArrayList<>();
    }

    public List<Node> getNodes() {
        return nodes;
    }

    public void setNodes(List<Node> nodes) {
        this.nodes = nodes;
    }

    public E getE() {
        return e;
    }

    public void setE(E e) {
        this.e = e;
    }
}
