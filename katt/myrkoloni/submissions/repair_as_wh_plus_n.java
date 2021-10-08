import java.util.*;
import java.io.*;

public class repair_as_wh_plus_n {
    public void run() throws IOException {
        in = new FastScanner(new FileInputStream("/dev/stdin"));
        out = new PrintWriter(new FileOutputStream("/dev/stdout"));

        int w = in.nextInt();
        int h = in.nextInt();
        int n = in.nextInt();
        int q = in.nextInt();

        int[][] cntP = new int[w + 1][h + 1];
        int[][] cntH = new int[w + 1][h + 1];
        int[][] cntV = new int[w + 1][h + 1];
        for (int i = 0; i < n - 1; i++) {
            String s = in.next();
            int x = in.nextInt();
            int y = in.nextInt();
            if (s.equals("h")) {
                cntP[x][y] = 1;
                cntP[x + 1][y] = 1;
                cntH[x + 1][y] = 1;
            } else {
                cntP[x][y] = 1;
                cntP[x][y + 1] = 1;
                cntV[x][y + 1] = 1;
            }
        }

        int[][] sumP = new int[w + 1][h + 1];
        int[][] sumH = new int[w + 1][h + 1];
        int[][] sumV = new int[w + 1][h + 1];
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                sumP[i][j] = cntP[i][j] + sumP[i - 1][j] + sumP[i][j - 1] - sumP[i - 1][j - 1];
                sumV[i][j] = cntV[i][j] + sumV[i - 1][j] + sumV[i][j - 1] - sumV[i - 1][j - 1];
                sumH[i][j] = cntH[i][j] + sumH[i - 1][j] + sumH[i][j - 1] - sumH[i - 1][j - 1];
            }
        }

        for (int i = 0; i < q; i++) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            int nv = sumP[x2][y2] - sumP[x1 - 1][y2] - sumP[x2][y1 - 1] + sumP[x1 - 1][y1 - 1];
            int ne = sumH[x2][y2] - sumH[x1][y2] - sumH[x2][y1 - 1] + sumH[x1][y1 - 1];
            ne += sumV[x2][y2] - sumV[x1 - 1][y2] - sumV[x2][y1] + sumV[x1 - 1][y1];
            //System.out.println(nv + " " + ne);
            out.println(nv - ne);
        }

        out.close();
    }

    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new repair_as_wh_plus_n().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws IOException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
            } catch (IOException e) {
                System.err.println(e);
                System.exit(1);
            }
            return st.nextToken();
       }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
