const
    MAXQ = 100000;

function experiment(N, Q: longint; var T: array of char; var K: array of longint): longint;
begin
    (* insert your code here *)
    experiment := 42;
end;


var
    N,Q,i : longint;
    T     : array[0..MAXQ-1] of char;
    K     : array[0..MAXQ-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, Q);
    for i:=0 to Q-1 do begin
        readln(fr, T[i], K[i]);
    end;

    writeln(fw, experiment(N, Q, T, K));
    close(fr);
    close(fw);
end.
