C++ System Programming Project: Client-Server Application for Shortest Path Calculation

This repository contains the implementation of a client-server application for calculating the shortest path between two nodes in an undirected graph. The application is written in C++ and utilizes the Breadth-First Search (BFS) algorithm for efficient pathfinding.

Server:

    Reads an undirected graph from a file
    Listens for client connections on a specified port
    Spawns a separate thread for each client connection
    Receives a pair of node IDs from the client
    Calculates the shortest path between the specified nodes using BFS
    Sends the shortest path back to the client

Client:

    Connects to the server on the specified IP address and port
    Sends the IDs of the two nodes for which to find the shortest path
    Receives the shortest path from the server
    Displays the shortest path
