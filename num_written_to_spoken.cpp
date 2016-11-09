#include <iostream>
#include <fst/fstlib.h>

using namespace std;
using namespace fst;

int main() {
	typedef StdArc::StateId StateId;

	StdVectorFst fst;
	// load ilabel
	SymbolTable *isyms = SymbolTable::ReadText("numbers.syms");
	// load olable
	SymbolTable *osyms = SymbolTable::ReadText("chars.syms");
	fst.SetInputSymbols(isyms);
	fst.SetOutputSymbols(osyms);

	StateId start = fst.AddState();
	fst.SetStart(start);
	StateId final = fst.AddState();
	fst.SetFinal(final, 1);

	// model each 亿 万 千 百 十 个 with three node (except without y0)
	// 0 is for path : 0 => 零 and disambiguate with previous 0 path (as an error path 00 => 零零)
	// 1 is for standard numbers transfer
	// 2 is for quantity
	StateId y1 = fst.AddState();
	StateId y2 = fst.AddState();
	StateId w0 = fst.AddState();
	StateId w1 = fst.AddState();
	StateId w2 = fst.AddState();
	StateId q0 = fst.AddState();
	StateId q1 = fst.AddState();
	StateId q2 = fst.AddState();
	StateId b0 = fst.AddState();
	StateId b1 = fst.AddState();
	StateId b2 = fst.AddState();
	StateId s0 = fst.AddState();
	StateId s1 = fst.AddState();
	StateId s2 = fst.AddState();
	StateId g1 = fst.AddState();
	StateId g2 = fst.AddState();
	// link the main path from y1 to g2
	fst.AddArc(y1, StdArc(1, 1, 1, y2));
	fst.AddArc(y1, StdArc(2, 2, 1, y2));
	fst.AddArc(y1, StdArc(3, 3, 1, y2));
	fst.AddArc(y1, StdArc(4, 4, 1, y2));
	fst.AddArc(y1, StdArc(5, 5, 1, y2));
	fst.AddArc(y1, StdArc(6, 6, 1, y2));
	fst.AddArc(y1, StdArc(7, 7, 1, y2));
	fst.AddArc(y1, StdArc(8, 8, 1, y2));
	fst.AddArc(y1, StdArc(9, 9, 1, y2));
	fst.AddArc(y2, StdArc(0, 15, 1, w0));
	fst.AddArc(w0, StdArc(0, 0, 1, w1));
	fst.AddArc(w1, StdArc(1, 1, 1, w2));
	fst.AddArc(w1, StdArc(2, 2, 1, w2));
	fst.AddArc(w1, StdArc(3, 3, 1, w2));
	fst.AddArc(w1, StdArc(4, 4, 1, w2));
	fst.AddArc(w1, StdArc(5, 5, 1, w2));
	fst.AddArc(w1, StdArc(6, 6, 1, w2));
	fst.AddArc(w1, StdArc(7, 7, 1, w2));
	fst.AddArc(w1, StdArc(8, 8, 1, w2));
	fst.AddArc(w1, StdArc(9, 9, 1, w2));
	fst.AddArc(w2, StdArc(0, 14, 1, q0));
	fst.AddArc(q0, StdArc(0, 0, 1, q1));
	fst.AddArc(q1, StdArc(1, 1, 1, q2));
	fst.AddArc(q1, StdArc(2, 2, 1, q2));
	fst.AddArc(q1, StdArc(3, 3, 1, q2));
	fst.AddArc(q1, StdArc(4, 4, 1, q2));
	fst.AddArc(q1, StdArc(5, 5, 1, q2));
	fst.AddArc(q1, StdArc(6, 6, 1, q2));
	fst.AddArc(q1, StdArc(7, 7, 1, q2));
	fst.AddArc(q1, StdArc(8, 8, 1, q2));
	fst.AddArc(q1, StdArc(9, 9, 1, q2));
	fst.AddArc(q2, StdArc(0, 13, 1, b0));
	fst.AddArc(b0, StdArc(0, 0, 1, b1));
	fst.AddArc(b1, StdArc(1, 1, 1, b2));
	fst.AddArc(b1, StdArc(2, 2, 1, b2));
	fst.AddArc(b1, StdArc(3, 3, 1, b2));
	fst.AddArc(b1, StdArc(4, 4, 1, b2));
	fst.AddArc(b1, StdArc(5, 5, 1, b2));
	fst.AddArc(b1, StdArc(6, 6, 1, b2));
	fst.AddArc(b1, StdArc(7, 7, 1, b2));
	fst.AddArc(b1, StdArc(8, 8, 1, b2));
	fst.AddArc(b1, StdArc(9, 9, 1, b2));
	fst.AddArc(b2, StdArc(0, 12, 1, s0));
	fst.AddArc(s0, StdArc(0, 0, 1, s1));
	fst.AddArc(s1, StdArc(1, 1, 1, s2));
	fst.AddArc(s1, StdArc(2, 2, 1, s2));
	fst.AddArc(s1, StdArc(3, 3, 1, s2));
	fst.AddArc(s1, StdArc(4, 4, 1, s2));
	fst.AddArc(s1, StdArc(5, 5, 1, s2));
	fst.AddArc(s1, StdArc(6, 6, 1, s2));
	fst.AddArc(s1, StdArc(7, 7, 1, s2));
	fst.AddArc(s1, StdArc(8, 8, 1, s2));
	fst.AddArc(s1, StdArc(9, 9, 1, s2));
	fst.AddArc(s2, StdArc(0, 11, 1, g1));
	fst.AddArc(g1, StdArc(1, 1, 1, g2));
	fst.AddArc(g1, StdArc(2, 2, 1, g2));
	fst.AddArc(g1, StdArc(3, 3, 1, g2));
	fst.AddArc(g1, StdArc(4, 4, 1, g2));
	fst.AddArc(g1, StdArc(5, 5, 1, g2));
	fst.AddArc(g1, StdArc(6, 6, 1, g2));
	fst.AddArc(g1, StdArc(7, 7, 1, g2));
	fst.AddArc(g1, StdArc(8, 8, 1, g2));
	fst.AddArc(g1, StdArc(9, 9, 1, g2));
	fst.AddArc(g1, StdArc(10, 0, 1, g2));
	fst.AddArc(g2, StdArc(0, 0, 1,final));

	// o is for suffix 0 path
	StateId o1 = fst.AddState();
	StateId o2 = fst.AddState();
	StateId o3 = fst.AddState();
	StateId o4 = fst.AddState();
	StateId o5 = fst.AddState();
	StateId o6 = fst.AddState();
	StateId o7 = fst.AddState();
	// link o* self path
	fst.AddArc(o1, StdArc(10, 0, 1, o2));
	fst.AddArc(o2, StdArc(10, 0, 1, o3));
	fst.AddArc(o3, StdArc(10, 0, 1, o4));
	fst.AddArc(o4, StdArc(10, 0, 1, o5));
	fst.AddArc(o5, StdArc(10, 0, 1, o6));
	fst.AddArc(o6, StdArc(10, 0, 1, o7));
	fst.AddArc(o7, StdArc(10, 0, 1, final));

	// z* is for 0 => 零 path
	StateId z1 = fst.AddState();
	StateId z2 = fst.AddState();
	StateId z3 = fst.AddState();
	StateId z4 = fst.AddState();
	StateId z5 = fst.AddState();
	StateId z6 = fst.AddState();
	StateId z7 = fst.AddState();
	// link z* self path
	fst.AddArc(z1, StdArc(10, 0, 1, z2));
	fst.AddArc(z2, StdArc(10, 0, 1, z3));
	fst.AddArc(z3, StdArc(10, 0, 1, z4));
	fst.AddArc(z4, StdArc(10, 0, 1, z5));
	fst.AddArc(z5, StdArc(10, 0, 1, z6));
	fst.AddArc(z6, StdArc(10, 0, 1, z7));

	// link start to *1
	fst.AddArc(start, StdArc(0, 0, 1, y1));
	fst.AddArc(start, StdArc(0, 0, 1, w1));
	fst.AddArc(start, StdArc(0, 0, 1, q1));
	fst.AddArc(start, StdArc(0, 0, 1, b1));
	fst.AddArc(start, StdArc(0, 0, 1, s1));
	fst.AddArc(start, StdArc(0, 0, 1, g1));
	fst.AddArc(start, StdArc(1, 11, 1, g1));

	// link *1 to z*
	fst.AddArc(w0, StdArc(10, 10, 1, z1));
	fst.AddArc(q0, StdArc(10, 10, 1, z5));
	fst.AddArc(b0, StdArc(10, 10, 1, z6));
	fst.AddArc(s0, StdArc(10, 10, 1, z7));
	// link z* to *1, escape 0 => 零 path
	fst.AddArc(z3, StdArc(0, 0, 1, w1));
	fst.AddArc(z4, StdArc(0, 0, 1, q1));
	fst.AddArc(z5, StdArc(0, 0, 1, b1));
	fst.AddArc(z6, StdArc(0, 0, 1, s1));
	fst.AddArc(z7, StdArc(0, 0, 1, g1));

	// link *2 to o*
	fst.AddArc(y2, StdArc(10, 15, 1, o1));
	fst.AddArc(w2, StdArc(10, 14, 1, o5));
	fst.AddArc(q2, StdArc(10, 13, 1, o6));
	fst.AddArc(b2, StdArc(10, 12, 1, o7));
	fst.AddArc(final, StdArc(0, 0, 1, w2));
	fst.AddArc(final, StdArc(0, 0, 1, y2));

	//	RmEpsilon(&fst); // dont't rm eps for clarity of pdf
	// Due to the input path doesn't corrspond only one output, like 13 => 一十三 or 十三,
	// the optmization: Determinize & Minimize, cannot be used.
	fst.Write("num_written_to_spoken.fst");

	return 0;
}
