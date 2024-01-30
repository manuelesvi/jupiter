#pragma once

#define _CRT_SECURE_NO_DEPRECATE
#include <objbase.h>
#include <iostream>
#include <fstream>
#include <sstream>

#define GVDLL 1

#include "cgraph.h"
#include "gvc.h"
#include "types.h"
#include "xdot.h"


using namespace std;


static int rj_afread(void* stream, char* buffer, int bufsize)
{
    istringstream* is = (istringstream*)stream;
    is->read(buffer, bufsize);
    int result = (int)is->gcount();
    return result;
}

static int rj_putstr(void* stream, const char* s)
{
    ostringstream* os = (ostringstream*)stream;
    (*os) << s;
    return 0;
}

static int rj_flush(void* stream)
{
    ostringstream* os = (ostringstream*)stream;
    os->flush();
    return 0;
}

static Agiodisc_t memIoDisc = { rj_afread, rj_putstr, rj_flush };
static Agdisc_t memDisc = { 0, 0, &memIoDisc };

extern "C" {

    void free_str(char* str);

#pragma region "CGraph"
    // Some wrappers around cgraph macros
    Agedge_t* rj_agmkin(Agedge_t* e);
    Agedge_t* rj_agmkout(Agedge_t* e);
    Agnode_t* rj_aghead(Agedge_t* edge);
    Agnode_t* rj_agtail(Agedge_t* edge);
    int rj_ageqedge(Agedge_t* e, Agedge_t* f);

    // Some wrappers around existing cgraph functions to handle string marshaling
    const char* rj_agmemwrite(Agraph_t* g);
    Agraph_t* rj_agmemread(const char* s);
    Agraph_t* rj_agopen(char* name, int graphtype);
    const char* rj_sym_key(Agsym_t* sym);

    double node_x(Agnode_t* node);
    double node_y(Agnode_t* node);
    double node_width(Agnode_t* node);
    double node_height(Agnode_t* node);

    textlabel_t* node_label(Agnode_t* node);
    textlabel_t* edge_label(Agedge_t* edge);
    textlabel_t* graph_label(Agraph_t* graph);

    double label_x(textlabel_t* label);
    double label_y(textlabel_t* label);
    double label_width(textlabel_t* label);
    double label_height(textlabel_t* label);
    const char* label_text(textlabel_t* label);
    double label_fontsize(textlabel_t* label);
    const char* label_fontname(textlabel_t* label);

    void clone_attribute_declarations(Agraph_t* from, Agraph_t* to);
    void convert_to_undirected(Agraph_t* graph);
#pragma endregion

#pragma region "xdot"

    size_t get_cnt(xdot* xdot);
    xdot_op* get_ops(xdot* xdot);
    xdot_kind get_kind(xdot_op* op);
    xdot_rect* get_ellipse(xdot_op* op);
    xdot_polyline* get_polygon(xdot_op* op);
    xdot_polyline* get_polyline(xdot_op* op);
    xdot_polyline* get_bezier(xdot_op* op);
    xdot_text* get_text(xdot_op* op);
    xdot_image* get_image(xdot_op* op);
    char* get_color(xdot_op* op);
    xdot_color* get_grad_color(xdot_op* op);
    xdot_font* get_font(xdot_op* op);
    char* get_style(xdot_op* op);
    unsigned int get_fontchar(xdot_op* op);
    xdot_rect* get_pos(xdot_image* img);
    char* get_name_image(xdot_image* img);
    double get_size(xdot_font* font);
    char* get_name_font(xdot_font* font);
    xdot_grad_type get_type(xdot_color* clr);
    char* get_clr(xdot_color* clr);
    xdot_linear_grad* get_ling(xdot_color* clr);
    xdot_radial_grad* get_ring(xdot_color* clr);
    double get_x_text(xdot_text* txt);
    double get_y_text(xdot_text* txt);
    xdot_align get_align(xdot_text* txt);
    double get_width(xdot_text* txt);
    char* get_text_str(xdot_text* txt);
    double get_x0_ling(xdot_linear_grad* ling);
    double get_y0_ling(xdot_linear_grad* ling);
    double get_x1_ling(xdot_linear_grad* ling);
    double get_y1_ling(xdot_linear_grad* ling);
    int get_n_stops_ling(xdot_linear_grad* ling);
    xdot_color_stop* get_stops_ling(xdot_linear_grad* ling);
    double get_x0_ring(xdot_radial_grad* ring);
    double get_y0_ring(xdot_radial_grad* ring);
    double get_r0_ring(xdot_radial_grad* ring);
    double get_x1_ring(xdot_radial_grad* ring);
    double get_y1_ring(xdot_radial_grad* ring);
    double get_r1_ring(xdot_radial_grad* ring);
    int get_n_stops_ring(xdot_radial_grad* ring);
    xdot_color_stop* get_stops_ring(xdot_radial_grad* ring);
    float get_frac(xdot_color_stop* stop);
    char* get_color_stop(xdot_color_stop* stop);
    size_t get_cnt_polyline(xdot_polyline* polyline);
    xdot_point* get_pts_polyline(xdot_polyline* polyline);
    double get_x_point(xdot_point* point);
    double get_y_point(xdot_point* point);
    double get_z_point(xdot_point* point);
    double get_x_rect(xdot_rect* rect);
    double get_y_rect(xdot_rect* rect);
    double get_w_rect(xdot_rect* rect);
    double get_h_rect(xdot_rect* rect);
    xdot_color_stop* get_color_stop_at_index(xdot_color_stop* stops, int index);
    xdot_op* get_op_at_index(xdot_op* ops, int index);
    xdot_point* get_pt_at_index(xdot_point* pts, int index);
#pragma endregion

#pragma region "testing/debugging"
    bool echobool(bool arg);
    int echoint(int arg);
    bool return_true();
    bool return_false();
    int return1();
    int return_1();

    typedef enum {
        Val1, Val2, Val3, Val4, Val5
    } TestEnum;

    TestEnum echo_enum(TestEnum e);
    TestEnum return_enum1();
    TestEnum return_enum2();
    TestEnum return_enum5();
    char* echo_string(char* str);
    char* return_empty_string();
    char* return_hello();
    int stackoverflow_repro();
    int missing_label_repro();
    int test_agread();
    int test_agmemread();
    int test_rj_agmemread();
#pragma endregion
}



