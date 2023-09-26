/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Doit_013
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());

        // 전형적인 큐 구현 문제
        Queue<Integer> queue = new LinkedList<>();

        for (int idx = 1; idx <= num; idx++) {
            queue.add(idx);
        }
        int temp;
        while (queue.size() != 1) {
            queue.poll();
            temp = queue.poll();
            queue.add(temp);
        }
        System.out.println(queue.poll());
    }
}