procedure Hello is
	
	procedure example is
	begin
		meow := meow + meow;
	end example;
	
	procedure bark ( top, tip : INTEGER ; abc :STRING) is
		a,b,c : ARRAY (1..5) of INTEGER;
	begin
		a(1):= 5;
	end bark;
	
	function foo return INTEGER is
	begin
		return 1;
	end example;
	
	function hi (hello:STRING) return FLOAT is
	begin
		return 1.0;
	end example;
	
	buf : INTEGER;
	ch : character;
begin
    bark(5,5);
	example;
	buf:=hi("hello"&"abc");
	
	
	for Iter in 1..5 loop
		if min = max then 
			buf:=hi("hello"&'a');
		elsif min < max then
			null;
		else
			null;
	end if;
	
	ch := 's';
	end loop;

end Hello;