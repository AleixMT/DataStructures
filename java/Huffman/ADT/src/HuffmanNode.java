public class HuffmanNode implements Comparable<HuffmanNode>{

    private String symbol;
    private int frequency = 0;
    private HuffmanNode left;
    private HuffmanNode right;

    public HuffmanNode(String symbol, int frequency, HuffmanNode left, HuffmanNode right) {
        this.symbol = symbol;
        this.frequency = frequency;
        this.left = left;
        this.right = right;
    }

    public HuffmanNode(String symbol) {
        this.symbol = symbol;
        this.frequency = 0;
        this.left = null;
        this.right = null;
    }

    public boolean isLeaf()
    {
        return this.left == null && this.right == null;
    }

    public HuffmanNode getLeft() {
        return left;
    }

    public void setLeft(HuffmanNode left) {
        this.left = left;
    }

    public HuffmanNode getRight() {
        return right;
    }

    public void setRight(HuffmanNode right) {
        this.right = right;
    }

    public String getSymbol() {
        return symbol;
    }

    public int getFrequency() {
        return frequency;
    }

    public void incrementFrequency() {
        this.frequency++;
    }

    @Override
    public int compareTo(HuffmanNode o) {
        return this.symbol.compareTo(o.getSymbol());
    }
}
