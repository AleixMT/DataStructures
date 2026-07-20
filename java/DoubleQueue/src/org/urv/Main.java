package org.urv;

import java.util.Stack;

public class Main {

    public static boolean esCapicua(String frase)
    {
        Stack<Character> stack1 = new Stack<Character>();
        Stack<Character> stack2 = new Stack<Character>();
        for (int i = 0; i < frase.length() / 2; i++)
        {
            stack1.push(frase.charAt(i));
        }
        while (! stack1.empty())
        {
            stack2.push(stack1.pop());
        }
        // Stack 2 tiene la mitad de la frase desde el principio.

        for (int i = frase.length() / 2; i < frase.length(); i++)
        {
            stack1.push(frase.charAt(i));
        }

        return stack1.equals(stack2);
    }


    public static boolean esCapicua2(String frase)
    {
        Stack<Character> stack1 = new Stack<Character>();
        Stack<Character> stack2 = new Stack<Character>();
        for (int i = 0; i < frase.length() / 2; i++)
        {
            stack1.push(frase.charAt(i));
        }

        // Stack 2 tiene la mitad de la frase desde el principio.
        for (int i = frase.length() - 1; i > frase.length() / 2 + 1; i--)
        {
            stack2.push(frase.charAt(i));
        }

        return stack1.equals(stack2);
    }

    public static boolean esCapicua2CuaIPila(String frase)
    {
        Stack<Character> stack1 = new Stack<Character>();
        Stack<Character> stack2 = new Stack<Character>();
        for (int i = 0; i < frase.length() / 2; i++)
        {
            stack1.push(frase.charAt(i));
        }

        // Stack 2 tiene la mitad de la frase desde el principio.
        for (int i = frase.length() - 1; i > frase.length() / 2 + 1; i--)
        {
            stack2.push(frase.charAt(i));
        }

        return stack1.equals(stack2);
    }

    public static boolean esCapicuaDobleCua(String frase) throws Exception {
        DoubleQueue<Character> queue = new DoubleQueueDynamicImpl<>();
        for (int i = 0; i < frase.length(); i++)
        {
            queue.addBottom(frase.charAt(i));
        }

        // Stack 2 tiene la mitad de la frase desde el principio.
        for (int i = 0; i < frase.length() / 2; i++)
        {
            if (! queue.popBottom().equals(queue.popTop()))
            {
                return false;
            }
        }

        return true;
    }

    public static boolean esVocal(Character a)
    {
        if ((((Character)a.charValue()).equals('a'))
            || (((Character)a.charValue()).equals('e'))
            || (((Character)a.charValue()).equals('i'))
            || (((Character)a.charValue()).equals('o'))
                || (((Character)a.charValue()).equals('u')))
            return true;

        return false;
    }

    public static String primeraFase(String frase)
    {
        int posIni = 0;
        int posVocal;

        String result = "";
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < frase.length(); i++)
        {
            if (esVocal(frase.charAt(i)))
            {
                posVocal = i;
                for (int j = posIni; j < posVocal - posIni; j++)
                {
                    stack.push(frase.charAt(j));
                }
                for (int j = posIni; j < posVocal - posIni; j++)
                {
                    result += stack.pop();
                }
                result += frase.charAt(i);
                posIni = i + 1;
            }
        }

        // TODO  ultima iteracion para invertir desde la ultima vocal hasta el final.

    }

    public static void main(String[] args) {

    }
}
