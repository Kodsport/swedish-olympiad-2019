import java.io.*;
import java.util.*;

public class repair_gk {
    static Scanner in;
    static int MAX_C = 300_000;
    
    class P {
        final int x, y;

        P(final int x, final int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(final Object o) {
            final P p = (P) o;
            return x == p.x && y == p.y;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    Map<P, List<P>> edges = new HashMap<>();
    Set<P> visited = new HashSet<>();
    @SuppressWarnings("unchecked")
    List<Integer>[][] inbound = new List[4][MAX_C];

    void addEdge(int x1, int y1, int x2, int y2) {
        P p1 = new P(x1, y1);
        List<P> list = edges.get(p1);
        if (list == null) {
            list = new ArrayList<>();
            edges.put(p1, list);
        }
        list.add(new P(x2, y2));
    }

    void run() {
//        long start = System.currentTimeMillis();
        int a = in.nextInt();
        int b = in.nextInt();
        int n = in.nextInt();
        int q = in.nextInt();

        for (int i = 1; i < n; i++) {
            char ch = in.next().charAt(0);
            int x = in.nextInt();
            int y = in.nextInt();

            if (ch == 'h') {
                addEdge(x, y, x + 1, y);
                addEdge(x + 1, y, x, y);
            } else {
                addEdge(x, y, x, y + 1);
                addEdge(x, y + 1, x, y);
            }
        }

//        System.out.println(System.currentTimeMillis() - start);
        for (List<Integer>[] lists : inbound) {
            for (int j = 0; j < lists.length; j++) {
                lists[j] = new ArrayList<>();
            }
        }

//        System.out.println(System.currentTimeMillis() - start);
        final P first = edges.keySet().iterator().next();
        visited.add(first);
        dfs(first);

//        System.out.println("dfs = " + (System.currentTimeMillis() - start));
        for (List<Integer>[] lists : inbound) {
            for (final List<Integer> list : lists) {
                Collections.sort(list);
            }
        }

//        System.out.println(System.currentTimeMillis() - start);
        for (int i = 0; i < q; i++) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();

            final boolean f = x1 <= first.x && first.x <= x2 && y1 <= first.y && first.y <= y2;
            final int i1 = f ? 1 : 0;
            final int c3 = count(inbound[3][x2], y1, y2 + 1);
            System.out.println(
                    i1
                    + count(inbound[0][y1 - 1], x1, x2 + 1)
                    + count(inbound[1][y2], x1, x2 + 1)
                    + count(inbound[2][x1 - 1], y1, y2 + 1)
                    + c3
            );
        }
    }

    private int count(final List<Integer> crosses, final int f, final int t) {
        int fb = search(crosses, f);
        int tb = search(crosses, t);
        return tb - fb;
    }

    private int search(final List<Integer> crosses, final int v) {
        int i = Collections.binarySearch(crosses, v);
        return i >= 0 ? i : -i - 1;
    }

    private void dfs(final P v) {
        for (P u : edges.get(v)) {
            if (visited.add(u)) {
                dfs(u);
                if (v.x == u.x) {
                    if (v.y < u.y) {
                        inbound[0][v.y].add(v.x);
                    } else {
                        inbound[1][u.y].add(u.x);
                    }
                } else {
                    if (v.x < u.x) {
                        inbound[2][v.x].add(v.y);
                    } else {
                        inbound[3][u.x].add(u.y);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner();
        new repair_gk().run();
    }

    static class Scanner {
        final BufferedReader reader;
        StringTokenizer tokenizer = new StringTokenizer("");

        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new AssertionError();
                }
            }
            return tokenizer.nextToken();
        }

        public void close() {
        }
    }
}
