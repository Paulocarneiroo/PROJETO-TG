class Graph:
    def __init__(self, edges):
        self.edges = edges
        self.mat = [[0 for _ in range(edges)] for _ in range(edges)]

    def printGraph(self):
        for i in range(self.edges):
            for j in range(self.edges):
                print(self.mat[i][j], end=' ')
            print()

    def connectEdges(self):
        print("Enter edges connections:")
        for i in range(self.edges):
            for j in range(self.edges):
                self.mat[i][j] = int(input(f"Position [{i}][{j}]: "))

def main():
    edges = int(input("Enter number of edges: "))

    graph = Graph(edges)
    graph.connectEdges()
    graph.printGraph()


if __name__ == "__main__":
   main()
