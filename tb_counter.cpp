#include <iostream>
#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vcounter* top = new Vcounter;
    VerilatedVcdC* trace = new VerilatedVcdC;
    top->trace(trace, 99);
    trace->open("waveform.vcd");

    vluint64_t sim_time = 0;

    // จำลองการทำงาน 50 รอบเวลา
    while (sim_time < 50) {
        // สร้างสัญญาณนาฬิกา (Clock Toggle ทุก 1 หน่วยเวลา)
        top->clk ^= 1;

        // สั่ง Reset ในช่วงเริ่มต้น (sim_time < 4)
        if (sim_time < 4) {
            top->rst = 1;
        } else {
            top->rst = 0;
        }

        top->eval();
        trace->dump(sim_time);
        sim_time++;
    }

    trace->close();
    delete top;
    delete trace;
    return 0;
}
