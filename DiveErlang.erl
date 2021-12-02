-module('DiveErlang').
-export([start/0]).

read_from_file() ->
    {ok, Input} = file:read_file("DiveInput.txt"),
    [Input].

get_input_list() ->
    RawInput = read_from_file(),
    RawInputList = string:split(RawInput, "\n", all),
    ShortList = lists:droplast(RawInputList),
    [ShortList].

processInput(L) ->
    
    
test_write_list(L) ->
    [io:fwrite("~p~n",[X]) || X <- L].

start() ->
    InputList = get_input_list(),
    test_write_list(InputList),
    TupleList = [string:to_integer(S) || S <- InputList],
    IntList = [element(1,X) || X <- TupleList],
    FinalList = [X*X || X <- IntList],
    test_write_list(FinalList).

