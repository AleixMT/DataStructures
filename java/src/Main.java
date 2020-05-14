import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        //List<Node<AirportInfo, Float>> nodes = graph.getNodes();
        Graph<AirportInfo, Float> graph = null;
        String filename = "airports_UW.net";
        int vertexNum = 0;
        File file = new File("data/" + filename);
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("ERROR: Fitxer no trobat. Abortant...");
            return;
        }

        if (scanner.hasNext())
        {
            vertexNum = Integer.parseInt(scanner.nextLine().split(" ")[1]);
            graph = new Graph<>(vertexNum);
        }

        int nodesCounter = 0;
        while (nodesCounter < vertexNum && scanner.hasNext())
        {
            String[] values = scanner.nextLine().split(" ");
            graph.addNode(new Node<AirportInfo, Float>(new AirportInfo(values[1], values[2], values[3])));
            nodesCounter++;
        }

        scanner.nextLine();  // Skip one informative line

        while (scanner.hasNext())
        {
            // Delete squeezed spaces (stupid and annoying format for a data file)
            String line = scanner.nextLine().trim().replaceAll(" +", " ");;

            String[] values = line.split(" ");
            Edge<AirportInfo, Float> edge = new Edge<AirportInfo, Float>(Float.parseFloat(values[2]));  // Initialize edge with weight

            // Add two nodes to the edge
            edge.getNodes().add(graph.getNodes().get(Integer.parseInt(values[0]) - 1));
            edge.getNodes().add(graph.getNodes().get(Integer.parseInt(values[1]) - 1));

            // Add the edges to the nodes
            graph.getNodes().get(Integer.parseInt(values[0]) - 1).getEdges().add(edge);
            graph.getNodes().get(Integer.parseInt(values[1]) - 1).getEdges().add(edge);
        }
        Heap heap = new Heap(graph);

        while (!heap.isEmpty())
        {
            heap.popFromGraph();
            System.out.println(heap.isAscending());

        }

    }
}

