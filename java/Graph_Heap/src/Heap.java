import java.util.ArrayList;
import java.util.List;

// Hard-coded for the problem of the airports
public class Heap<T extends Comparable<T>, E extends Comparable<E>> {

    private ArrayList<Node<T, E>> heap;

    public Heap(Graph graph)
    {
        List<Node<T, E>> nodes = graph.getNodes();

        heap = new ArrayList<>();
        // Construct heap
        for (Node<T, E> node: nodes)
        {
            this.push(node);
        }
        //this.graph = graph;  // Save graph for later manipulation
    }

    // Constructor for a list that alrady stores a MaxHeap
    public Heap(ArrayList<Node<T, E>> list)
    {
        this.heap = list;
    }

    // Returns peek of max heap (node with most connections)
    public Node<T, E> peek()
    {
        return heap.get(0);
    }

    /*
     * Returns peek of max heap (node with most connections), removes it from the heap, reheapify from root,
     * update data and reheapify each node that lost connections
     */
    public Node<T, E> pop()
    {
        Node deleted = peek();

        // Swap root element and last element (to maintain most of structure consistency)
        swap(0, this.heap.size() - 1);
        // Remove "root" element (that is no longer root)
        this.heap.remove(this.heap.size() - 1);

        heapify(0);  // Reheapify from root

        return deleted;
    }

    public Node<T, E> popFromGraph()
    {
        Node <T, E> deleted = this.pop();
        List<Edge<T, E>> deletedEdges = deleted.getEdges();

        for (Edge edge: deletedEdges)  // for each edge
        {
            List<Node<T, E>> deletedNodes = edge.getNodes();  // Nodes that are connected using the current edge
            deletedNodes.remove(deleted);  // Delete the Node to be deleted from the list

            // pos 0 is the "other" Node that connects with the edge. Delete that edge from the list
            deletedNodes.get(0).getEdges().remove(edge);

            // Reheapify from the position of the node that has lost one edge
            heapify(heap.indexOf(deletedNodes.get(0)));
        }
        return deleted;
    }

    // Adds a node to the heap (at the end) and sort to fit the proposition of the maxheap
    public void push(Node<T, E> item)
    {
        // Add the element at the end
        heap.add(item);

        // Heapify upwards
        int index = heap.size() - 1;

        // While we don't satisfy the condition or we get to the root propagate new Node
        while (hasParent(index) && parent(index).getEdges().size() < heap.get(index).getEdges().size())
        {
            swap(posParent(index), index);
            index = posParent(index);
        }
    }

    // Returns true if the list is empty (delegated method)
    public boolean isEmpty()
    {
        return this.heap.isEmpty();
    }

    // return the size of the heap (delegated method)
    public int size()
    {
        return this.heap.size();
    }

    @Override
    public String toString()
    {
        int index = 1;
        int height = 0;
        String builder = "";
        for (Node<T, E> node: this.heap)
        {
            if (index == Math.pow(2, height))
            {
                height++;
                builder += "\n";
            }

            builder += ((Integer)node.getEdges().size()).toString() + " ";

            index++;
        }
        return builder;
    }

    public boolean isAscending()
    {
        Heap<T, E> tmp = new Heap<T, E>((ArrayList<Node<T, E>>) this.heap.clone());
        int current;
        int maximum = Integer.MAX_VALUE;
        boolean condition = true;
        while (!tmp.isEmpty() && condition)
        {
            current = tmp.pop().getEdges().size();
            condition &= maximum >= current;
            maximum = current;
        }
        return condition;
    }

    /*
     * PRIVATE FUNCTIONS TO MANAGE THE HEAP
     */

    // When a parent is deleted, reconvert the DE subtrees to fit to a maxheap definition using the number of connections
    private void heapify(int index) {

        int left, right, parent;

        // Soft condition to enter to the while... We eat one more free loop when not necessary
        while (hasLeftChild(index) || hasRightChild(index))
        {
            parent = this.heap.get(index).getEdges().size();
            if (hasLeftChild(index))
            {
                left = leftChild(index).getEdges().size();
            }
            else
            {
                left = Integer.MIN_VALUE;
            }
            if (hasRightChild(index))
            {
                right = rightChild(index).getEdges().size();
            }
            else
            {
                right = Integer.MIN_VALUE;
            }

            // We satisfy the condition, so we leave
            if ((right <= parent) && left <= parent) break;

            // At this point we are not satifying the condition
            // If we have both values wrong, let'd decide which is the correct to put on the root
            // Exclusive if blocks
            if (left > parent && right > parent)
            {
                // If left > right, we put left in the root
                if (left > right)
                {
                    swap(index, posLeftChild(index));
                    // We keep the index to propagate in next iteration
                    index = posLeftChild(index);
                }
                else  // If left <= right, we put right in the root
                {
                    swap(index, posRightChild(index));
                    // We keep the index to propagate in next iteration
                    index = posRightChild(index);
                }
            }
            // Only left is misplaced
            else if (left > parent)
            {
                swap(index, posLeftChild(index));
                // We keep the index to propagate in next iteration
                index = posLeftChild(index);
            }
            else  // right > parent (!! NOT =, BECAUSE WE DELETED THAT POSSIBILITY)
            {
                swap(index, posRightChild(index));
                // We keep the index to propagate in next iteration
                index = posRightChild(index);
            }
        }
    }

    // Returns true if it has parent
    private boolean hasParent(int index) {
        return posParent(index) >= 0;
    }

    // Returns pos of parent
    private int posParent(int pos)
    {
        return (pos - 1)/ 2;
    }

    // Returns the parent Node
    private Node parent(int childIndex) {
        return heap.get(posParent(childIndex));
    }

    // return true if it has left child
    private boolean hasLeftChild(int index) {
        return posLeftChild(index) < heap.size();
    }

    // Returns left child
    private int posLeftChild(int pos)
    {
        return 2 * pos + 1;
    }

    // Returns the left child Node
    private Node leftChild(int parentIndex)
    {
        return heap.get(posLeftChild(parentIndex));
    }

    // Returns true if it has right child
    private boolean hasRightChild(int index) {
        return posRightChild(index) < heap.size();
    }

    // Returns right child
    private int posRightChild(int pos)
    {
        return 2 * pos + 2;
    }

    // Returns the right child Node
    private Node rightChild(int parentIndex)
    {
        return heap.get(posRightChild(parentIndex));
    }

    // Swaps two given elements
    private void swap(int i, int j)
    {
        Node<T, E> tmp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, tmp);
    }





}
