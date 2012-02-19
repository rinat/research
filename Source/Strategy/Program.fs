open Strategy

let characters = 
    [(new Troll() :> Character);
     (new King() :> Character)]

let main() =
    characters
    |> Seq.iter (fun x -> x.Say(); x.Attack())

main()