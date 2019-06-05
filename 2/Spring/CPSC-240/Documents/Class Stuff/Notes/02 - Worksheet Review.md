# Notes

# Modern Architecture
  - We use the Von Neumann architecture
  - The difference between the Harvard and V.N arch is that there is only one block of memory in V.N, only allowing for one bus of memory
  - Modified Harvard allows for permissions in pages for chunks of memory
# Clocks
  - Make sure the instructions sent on the bus and the CPU operations are in sync
  - time of a single operation
    - period of a sinusoidal function
  - used to trigger events


# Instruction Execution Cycle
  - Fetch
  - Decode
  - Fetch operands
  - Execute
  - Store output

# Reading from memory
  - Much slower than CPU reading
    - Distance from the CPU
    - SRAM is in the CPU rather than DDR[0-9] ram
  - Each byte has an address in memory
    - These addresses are represented in hex strings
# Registers
  - 16 registers
    - 64 bit size for each of the registers
  - R{8-15}
  - RIP
    - Instruction Pointer
  - jmp, call, branch
    - branch to other part of the program
  - Naming is historical
  - We will be using the general purpose registers (16 of them)
  - Helpful link -> "6.035.scripts.mit.edu/sp17/x86-64-architecture-guide.html"

# Flags
  - C: Carry
  - P: Parity
  - A: Adjust
  - Z: Zero
  - S: Sign
  - D: Direction
  - O: Overflow
