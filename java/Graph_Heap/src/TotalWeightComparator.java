import java.util.Comparator;

public class TotalWeightComparator implements Comparator<Node<AirportInfo, Float>> {

    public int compare(Node<AirportInfo, Float> n1, Node<AirportInfo, Float> n2){
        float sum1 = 0;
        for (Edge<AirportInfo, Float> edge1 : n1.getEdges())
        {
            sum1 += (Float) edge1.getE();
        }

        float sum2 = 0;
        for (Edge<AirportInfo, Float> edge2 : n2.getEdges())
        {
            sum2 += (Float) edge2.getE();
        }
        if (sum1 > sum2)
        {
            return 1;
        }
        else if (sum1 < sum2)
        {
            return -1;
        }
        else return 0;

    }

}