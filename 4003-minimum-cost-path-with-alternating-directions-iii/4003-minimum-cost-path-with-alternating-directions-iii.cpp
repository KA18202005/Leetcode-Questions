class Solution {
public:
    struct Node {
        long long cost;
        int x, y;
        int parity;      // 0 = odd action next, 1 = even action next

        bool operator>(const Node &other) const {
            return cost > other.cost;
        }
    };

    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        const long long INF = 1e18;

        // dist[row][col][parity]
        vector<vector<array<long long,2>>> dist(
            m, vector<array<long long,2>>(n, {INF, INF})
        );

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // Start at (0,0)
        dist[0][0][0] = 1;          // next action is Odd
        pq.push({1, 0, 0, 0});

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!pq.empty()) {

            Node cur = pq.top();
            pq.pop();

            long long cost = cur.cost;
            int x = cur.x;
            int y = cur.y;
            int parity = cur.parity;

            if (cost != dist[x][y][parity])
                continue;

            if (x == m - 1 && y == n - 1)
                return cost;

            //---------------- WAIT ----------------//

            long long waitCost = cost + penalty[x][y];

            if (waitCost < dist[x][y][parity ^ 1]) {
                dist[x][y][parity ^ 1] = waitCost;
                pq.push({waitCost, x, y, parity ^ 1});
            }

            //---------------- MOVE ----------------//

            for (int dir = 0; dir < 4; dir++) {

                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                long long newCost = cost;

                // Entry cost
                newCost += 1LL * (nx + 1) * (ny + 1);

                bool validMove = false;

                if (parity == 0) {          // Odd action
                    if (dir == 0 || dir == 1)
                        validMove = true;   // Right or Down
                }
                else {                      // Even action
                    if (dir == 2 || dir == 3)
                        validMove = true;   // Left or Up
                }

                if (!validMove)
                    newCost += penalty[x][y];

                if (newCost < dist[nx][ny][parity ^ 1]) {
                    dist[nx][ny][parity ^ 1] = newCost;
                    pq.push({newCost, nx, ny, parity ^ 1});
                }
            }
        }

        return -1;
    }
};