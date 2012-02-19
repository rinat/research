namespace Strategy

type SpeechBehavior =
    abstract Say : unit -> unit

type Growl() = 
    member this.Say() = (this :> SpeechBehavior).Say()
    interface SpeechBehavior with
        member x.Say() = printfn "<< Rrrrrrrrrr >>"

type HumanSpeech() = 
    member this.Say() = (this :> SpeechBehavior).Say()
    interface SpeechBehavior with
        member this.Say() = printfn "Hello"