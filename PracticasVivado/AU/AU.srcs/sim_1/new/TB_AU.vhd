library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity ALU_tb is
end;

architecture bench of ALU_tb is

  component ALU
      Port ( A,B : in STD_LOGIC_VECTOR (3 downto 0);
             BINVERT : in STD_LOGIC;
             S : out STD_LOGIC_VECTOR (3 downto 0);
             C4 : out STD_LOGIC);
  end component;

  signal A,B: STD_LOGIC_VECTOR (3 downto 0);
  signal BINVERT: STD_LOGIC;
  signal S: STD_LOGIC_VECTOR (3 downto 0);
  signal C4: STD_LOGIC;

begin

  uut: ALU port map ( A       => A,
                      B       => B,
                      BINVERT => BINVERT,
                      S       => S,
                      C4      => C4 );

  stimulus: process
  begin
  
    A <= "0101";
    B <= "0011";
    BINVERT <= '0';
    
    WAIT FOR 200 ns;
    BINVERT <= '1';

    wait;
  end process;


end;
