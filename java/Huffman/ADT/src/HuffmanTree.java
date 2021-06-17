public class HuffmanTree implements Comparable<HuffmanTree> {
    private HuffmanNode root;

    public HuffmanTree() {
        this.root = null;
    }

    public HuffmanTree(HuffmanNode root) {
        this.root = root;
    }

    public HuffmanTree(String symbol) {
        this.root = new HuffmanNode(symbol);
    }


    @Override
    public int compareTo(HuffmanTree o) {
        return this.root.compareTo(o.getRoot());
    }

    public HuffmanNode getRoot() {
        return root;
    }

    /**
     * Receives a trivial Huffman tree and extends the self structure with it.
     */
    public void append(HuffmanTree triv)
    {
        if (this.root == null)
        {
            this.root = triv.root;
        }
        else
        {
            HuffmanNode newParent = new HuffmanNode("");
            newParent.setRight(this.root);
            newParent.setLeft(triv.getRoot());
            this.root = newParent;
        }
    }


}
