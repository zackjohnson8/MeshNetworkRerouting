# Network 400 Disrupted Mesh Network
By combining both Dijkstra and MST Prim's algorithms we have developed a unique way of traversing through a network of nodes/routes. Initially the package begins from any node in the network with a destination also given. The node who receives the package will begin finding the lowest weight path using Dijkstra. After the best path has been determined, the start node begins the delivery process. If during this delivery the path has been broken due to a unresponsive node, the current position of the package must find a new path from current node to destination node. This is done using the MST(Minimal Spanning Tree) Prim's editions of the algorithm. Once the new path is determined, the package is then retransmitted from current node to destination node.

COMPILE:
Using Ubuntu Linux Distro in terminal run the following code,
make
./NodeSim
