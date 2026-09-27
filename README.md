# verilog-oss
demo run verilog with oss (Open-Source Software)

- verilator  : tranform verilog to c++ for simulation and dump .vcd
- gtk_wave   : view waveform
- yosys      : synthesis


using this command to *creat simulation*
`verilator --cc counter.v --exe tb_counter.cpp --trace --build -o sim_counter`
and then *run simualation*
`./obj_dir/sim_counter`
view waveform 
`gtkwave waveform.vcd`
synthesis and view schematic 
`yosys -p "read_verilog counter.v; synth -top counter; show"`
