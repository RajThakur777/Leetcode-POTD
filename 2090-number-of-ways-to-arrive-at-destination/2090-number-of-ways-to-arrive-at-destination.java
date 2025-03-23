class Pair {
    long a; // distance
    long b; // node

    Pair(long a, long b) {
        this.a = a;
        this.b = b;
    }
}


class Solution {
    public int countPaths(int n, int[][] roads) {
        PriorityQueue<Pair> q = new PriorityQueue<>((x, y) -> Long.compare(x.a, y.a));
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] ar : roads) {
            adj.get(ar[0]).add(new Pair(ar[1], ar[2])); // node wt
            adj.get(ar[1]).add(new Pair(ar[0], ar[2]));
        }

        long[] dis = new long[n];
        int[] ways = new int[n];

        Arrays.fill(dis, Long.MAX_VALUE / 2);
        dis[0] = 0;
        ways[0] = 1;
        q.add(new Pair(0, 0));

        while (!q.isEmpty()) {
            long pd = q.peek().a;
            long node = q.peek().b;
            q.remove();

            for (Pair i : adj.get((int) node)) {
                long edgewt = i.b;
                long adjnode = i.a;

                if (edgewt + pd < dis[(int) adjnode]) {
                    dis[(int) adjnode] = edgewt + pd;
                    q.add(new Pair(dis[(int) adjnode], adjnode));
                    ways[(int) adjnode] = ways[(int) node];
                } 
                else if (edgewt + pd == dis[(int) adjnode]) {
                    ways[(int) adjnode] = (ways[(int) adjnode] + ways[(int) node]) % ((int) 1e9 + 7); 
                }
            }
        }

        return ways[n - 1] % ((int) 1e9 + 7);
    }
}