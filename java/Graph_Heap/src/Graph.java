import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Graph<T extends Comparable<T>, E extends Comparable<E>> {

    private List<Node<T, E>> nodes;

    public Graph(int size)
    {
        this.nodes = new ArrayList<>(size);
    }

    public List<Node<T, E>> getNodes() {
        return nodes;
    }

    public void addNode(Node<T, E> node)
    {
        nodes.add(node);
    }
}
