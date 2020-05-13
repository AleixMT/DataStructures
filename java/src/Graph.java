import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Graph {

    private List<Node> nodes;

    public Graph(String filename)
    {
        File file = new File("data/" + filename);
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("ERROR: Fitxer no trobat. Abortant...");
            return;
        }

        int vertexNum = 0;
        if (scanner.hasNext())
        {
            vertexNum = Integer.parseInt(scanner.nextLine().split(" ")[1]);  // Initialize node with name
            nodes = new ArrayList<>(vertexNum);
        }

        int nodesCounter = 0;
        while (nodesCounter < vertexNum && scanner.hasNext())
        {
            String[] values = scanner.nextLine().split(" ");
            nodes.add(new Node(values[1]));
            nodesCounter++;
        }

        System.out.println(scanner.nextLine());  // Skip one informative line

        while (scanner.hasNext())
        {
            // Delete squeezed spaces (stupid and annoying format for a data file)
            String line = scanner.nextLine().trim().replaceAll(" +", " ");;
            System.out.println(line);

            String[] values = line.split(" ");
            Edge edge = new Edge(Float.parseFloat(values[2]));  // Initialize edge with weight

            // Add two nodes to the edge
            edge.getNodes().add(nodes.get(Integer.parseInt(values[0]) - 1));
            edge.getNodes().add(nodes.get(Integer.parseInt(values[1]) - 1));

            // Add the edges to the nodes
            nodes.get(Integer.parseInt(values[0]) - 1).getEdges().add(edge);
            nodes.get(Integer.parseInt(values[1]) - 1).getEdges().add(edge);
        }
    }

    public List<Node> getNodes() {
        return nodes;
    }
}
