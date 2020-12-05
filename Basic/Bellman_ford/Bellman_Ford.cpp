struct Edge {
    int src;
    int dest;
    int weight;
}

vector <Edge> edges;
// or vector <Edge> edges[nodecount]

void bellman_ford(int src) {
    int* dist = malloc(sizeof(int) * nodecount);
    // initial
    for (int i=0; i < nodecount; i++){
        if (i == src) dist[i] = 0;
        else dist[i] = INF;
    }
    
    // opeation
    for (int i=0; i < nodecount; i++) {
        for (int j=0; j < edgecount; j++) {
            if (dist[edges[j] != INF && dist[edges[j].dest] > dist[edges[j].src] + edges[j].weight) {
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
            }
        }
    }
    // check
    for (int i=0; i< edgecount; i++){
        if (dist[edges[i].dest] > dist[edges[i].src] + edges[i].weight)
        {
            assert(cycle);
            break;
        }
    }
    for (int i=0; i < nodecount ; i++){
        cout << "SSP %d = " << dist[i] << endl;
    }
}

