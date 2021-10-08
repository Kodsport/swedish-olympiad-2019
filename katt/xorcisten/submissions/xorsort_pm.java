import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class xorsort_pm {

    public static final int BITS = 30;
    private int[] a;
    private int[][] r;
    private long ans;

    private void solve() throws IOException {
        int n = nextInt();
        a = new int[n];
        r = new int[2][BITS];
        ans = 0;
        for (int i = 0; i < n; i++) {
            set(i, nextInt());
        }
        //ans += getRes();
        out.println(getRes());
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int p = nextInt();
            int b = nextInt();
            set(p - 1, b);
            //ans += getRes();
            out.println(getRes());
        }
        //out.println(ans);
    }

    private void set(int i, int v) {
        if (i > 0) {
            update(i - 1, -1);
        }
        if (i < a.length - 1) {
            update(i, -1);
        }
        a[i] = v;
        if (i > 0) {
            update(i - 1, 1);
        }
        if (i < a.length - 1) {
            update(i, 1);
        }
    }

    private void update(int i, int d) {
        for (int j = BITS - 1; j >= 0; j--) {
            int x = (a[i] >> j) & 1;
            int y = (a[i + 1] >> j) & 1;
            if (x != y) {
                r[x][j] += d;
                break;
            }
        }
    }

    public int getRes() {
        int res = 0;
        for (int j = 0; j < 30; j++) {
            if (r[0][j] > 0 && r[1][j] > 0) return -1;
            if (r[1][j] > 0) {
                res += 1 << j;
            }
        }
        return res;
    }

    // ------------------

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new xorsort_pm().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

}
