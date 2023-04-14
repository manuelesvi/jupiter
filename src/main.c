#include <stdio.h>
#include <stdlib.h>
#include <gvc.h>
#include <cgraph.h>
#include <cdt.h>

int main(int argc, char * argv[])
{
        printf("Hello from %s!\n", argv[0]);
	
	// set up a graphviz context
	GVC_t *gvc = gvContext();

	// parse command line args - minimally argv[0] sets layout engine
	// gvParseArgs(gvc, argc, argv);

	// Create a simple digraph
	Agraph_t *g = agopen("g", Agdirected, 0);
	Agnode_t *n = agnode(g, "n", 1);
	Agnode_t *m = agnode(g, "m", 1);
	agedge(g, n, m, 0, 1);

	// Compute a layout using layout engine from command line args
	// gvLayoutJobs(gvc, g);
	
	gvLayout(gvc, g, "dot");

	// Write the graph according to -T and -o options
	// gvRenderJobs(gvc, g);
	FILE *file = fopen("test.png", "w");
	gvRender(gvc, g, "png", file);
	fflush(file);
	fclose(file);

	// Free layout data
	gvFreeLayout(gvc, g);

	// Free graph structures
	agclose(g);

	// close output file, free context, and return number of errors
	return gvFreeContext(gvc);
}
