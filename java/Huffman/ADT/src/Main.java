import java.util.Iterator;

public class Main {
    public static void main(String[] args) {

        GenericList<Integer> genericList = new GenericList<>();
        genericList.add(5);
        genericList.add(5);
        genericList.add(3);
        genericList.add(5);
        genericList.add(5);
        genericList.add(4);
        genericList.add(3);
        genericList.add(5);
        genericList.add(5);

        Iterator<Integer> itera = genericList.iterator();
        while (itera.hasNext()) {
            System.out.println(itera.next());
        }

        System.out.println(genericList.get(0));
        System.out.println(genericList.get(1));
        System.out.println(genericList.get(2));
        System.out.println(genericList.get(3));
        System.out.println(genericList.get(5));

        genericList.remove(5);
        itera = genericList.iterator();
        System.out.println("end");
        while (itera.hasNext()) {
            System.out.println(itera.next());
        }

        String entry = "AAABBCD";
        GenericList<HuffmanTree> entrylist = new GenericList<>();
        for (int i = 0; i < entry.length(); i++)
        {
            String input = String.valueOf(entry.charAt(i));
            HuffmanTree presentValue = entrylist.search(new HuffmanTree(input));
            if (presentValue == null)
            {
                entrylist.add(new HuffmanTree(input));
            }
            else
            {
                presentValue.getRoot().incrementFrequency();
            }
        }

        // Now we have the entry nodes to perform the algorithm

        HuffmanTree result = new HuffmanTree();
        

    }

}