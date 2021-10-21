library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ALU is
    GENERIC (N : integer :=4);
    Port ( A,B : in STD_LOGIC_VECTOR (N-1 downto 0);
           BINVERT : in STD_LOGIC;
           S : out STD_LOGIC_VECTOR (N-1 downto 0);
           CN : out STD_LOGIC);
end ALU;

architecture Programa of ALU is
--signal EB : STD_LOGIC_VECTOR (3 downto 0);
--signal C : STD_LOGIC_VECTOR (4 downto 0);
-- ASIGNACION DE TERMINALES (LEDS)--

begin
    -- C(0) <= BINVERT;

    -- EB(0) <= B(0) xor BINVERT;
    -- S(0) <= A(0) xor EB(0) XOR C(0);
    -- C(1) <= (A(0) AND C(0)) OR (EB(0) AND C(0)) OR (A(0) AND EB(0));
    
    -- EB(1) <= B(1) xor BINVERT;
    -- S(1) <= A(1) xor EB(1) XOR C(1);
    -- C(2) <= (A(1) AND C(1)) OR (EB(1) AND C(1)) OR (A(1) AND EB(1));
    
    -- EB(2) <= B(2) xor BINVERT;
    -- S(2) <= A(2) xor EB(2) XOR C(2);
    -- C(3) <= (A(2) AND C(2)) OR (EB(2) AND C(2)) OR (A(2) AND EB(2));
    
    -- EB(3) <= B(3) xor BINVERT;
    -- S(3) <= A(3) xor EB(3) XOR C(3);
    -- C4 <= (A(3) AND C(3)) OR (EB(3) AND C(3)) OR (A(3) AND EB(3));

    -- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>USANDO UN CICLO FOR>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
--    C(0) <= BINVERT;
--    CICLO: for i in 0 to 3 generate
--    EB(i) <= B(i) xor BINVERT;
--    S(i) <= A(i) xor EB(i) XOR C(i);
--    C(i+1) <= (A(i) AND C(i)) OR (EB(i) AND C(i)) OR (A(i) AND EB(i));
    
--    end generate ; -- CICLO
--    C4 <= C(4);
    -- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Otro FOR SECUENCIAL>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    PAU : process( A,B,BINVERT )
    VARIABLE EB : std_logic_vector (3 downto 0) := "0000";
    VARIABLE C : std_logic_vector (4 downto 0) := "00000";
    begin
       C(0) := BINVERT;
       for i in 0 to N-1 loop
        EB(i) := B(i) xor BINVERT;
        S(i) <= A(i) xor EB(i) XOR C(i); --SALIDA SUMADOR
        C(i+1) := (A(i) AND C(i)) OR (EB(i) AND C(i)) OR (A(i) AND EB(i));
       end loop ; --    
       CN <= C(N);
    end process; -- PAU

end Programa;
