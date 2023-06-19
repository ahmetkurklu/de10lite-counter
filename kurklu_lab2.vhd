library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity kurklu_lab2 is
	port(
		clk : in std_logic := '0';
		reset_n : in std_logic :='0';
		segment1 : out std_logic_vector(6 downto 0);
		segment2 : out std_logic_vector(6 downto 0);
		segment3 : out std_logic_vector(6 downto 0));
		
end entity kurklu_lab2;



architecture rit of kurklu_lab2 is
	component kurklu_lab2_sys is
        port (
            clk_clk                         : in  std_logic                    := 'X'; -- clk
            reset_reset_n                   : in  std_logic                    := 'X'; -- reset_n
            seg1_external_connection_export : out std_logic_vector(3 downto 0);        -- export
            seg2_external_connection_export : out std_logic_vector(3 downto 0);        -- export
            seg3_external_connection_export : out std_logic_vector(3 downto 0)         -- export
        );
    end component kurklu_lab2_sys;
	 
	component bin_to_7seg is
			port(
				input : in std_logic_vector(3 downto 0):= (others => 'X');
				output : out std_logic_vector(6 downto 0));
			
	end component bin_to_7seg;

signal tmp1 : std_logic_vector(3 downto 0);
signal tmp2 : std_logic_vector(3 downto 0);
signal tmp3 : std_logic_vector(3 downto 0);
begin



	u0 : component kurklu_lab2_sys
        port map (
            clk_clk                         => clk,                         --                      clk.clk
            reset_reset_n                   => reset_n,                   --                    reset.reset_n
            seg1_external_connection_export => tmp1,
				seg2_external_connection_export => tmp2, 
            seg3_external_connection_export => tmp3);
		  

	convert1 : component bin_to_7seg
			port map (
				input => tmp1,
				output => segment1);
				
				
	convert2 : component bin_to_7seg
			port map (
				input => tmp2,
				output => segment2);

	convert3 : component bin_to_7seg
			port map (
				input => tmp3,
				output => segment3);
		  
end architecture;





