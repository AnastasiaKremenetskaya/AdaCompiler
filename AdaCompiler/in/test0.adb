procedure your_name is
	procedure test is 
    begin
        null;
    end Test;
	
	number  : Integer := 5;
	symbol  : Character := 'h';
	pi 		: Float := 3.14;
	str_arr	: string(1..100);
	num_arr : array(1..5) of Integer;
	str 	: string := "asdsfsd""dsads""";
	number2 : Integer;
	len     : Integer := 0;
begin
	number2 := 5;
	pi 		:= 5.5e7+3.3;;
	pi 		:= 5.5e+3.3;
	len 	:= num_arr'Length;
	
	put("function's"""" parameters"); --put("commented function");

	for i in 1..10 loop            
		put_line("Hello, world!--Put_Line" & '"' & "'");
	end loop;
	
	for i in str'Range loop
        null;
    end loop;
	
	if number < .18 then
		number2 := number + 1;
	elsif number >= 60 then
		number2 := 4 / 2;
	else
		number2 := 4 ** 2;
	end if;
	
	Func;
	
	return;
end your_name; 