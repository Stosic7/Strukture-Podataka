#include <queue>
#include <cstdlib>  // abs

// Pomoćno: reset pred/visited za sve čvorove u grafu
static void resetBFS(Node* first) {
    for (Node* u = first; u; u = u->next) {
        u->visited = false;
        u->pred = nullptr;
    }
}

// Broji ivice od start do t praćenjem pred pokazivača; ako nema puta, vrati -1
static int distanceByPred(Node* t, Node* start) {
    if (!t || !start) return -1;
    int d = 0;
    for (Node* u = t; u && u != start; u = u->pred) ++d;
    return (t && start && (t == start || t->pred || d >= 0)) ? d : -1;
}

Node* GraphInt::minConnectingFlights(Node* start, Node* goal1, Node* goal2, int& diff)
{
    // 0) zaštita
    diff = 0;
    if (!start || (!goal1 && !goal2)) return nullptr;

    // 1) reset pred/visited
    resetBFS(this->first);

    // 2) BFS iz start-a
    std::queue<Node*> q;
    start->visited = true;
    start->pred = nullptr;
    q.push(start);

    bool seen1 = (start == goal1);
    bool seen2 = (start == goal2);

    while (!q.empty() && !(seen1 && seen2))
    {
        Node* u = q.front(); q.pop();
        for (Edge* e = u->adj; e; e = e->next)
        {
            Node* v = e->dest;
            if (!v->visited) {
                v->visited = true;
                v->pred = u;
                q.push(v);
                if (v == goal1) seen1 = true;
                if (v == goal2) seen2 = true;
            }
        }
    }

    int d1 = goal1 ? distanceByPred(goal1, start) : -1;
    int d2 = goal2 ? distanceByPred(goal2, start) : -1;

    const int INF = 1e9;
    int dd1 = (d1 >= 0) ? d1 : INF;
    int dd2 = (d2 >= 0) ? d2 : INF;

    diff = (dd1 == INF || dd2 == INF) ? std::abs(dd1 - dd2) : std::abs(d1 - d2);

    if (dd1 < dd2)      return goal1;          
    else if (dd2 < dd1) return goal2;          
    else                return goal1;          
}
