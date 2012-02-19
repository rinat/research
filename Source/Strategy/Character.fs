namespace Strategy

[<AbstractClass>]
type Character(_flyBehavior : IAttackBehavior, _humanSpeechBehavior : SpeechBehavior) =
    member this.Attack() = (this :> IAttackBehavior).Attack()
    member this.Say() = (this :> SpeechBehavior).Say()

    interface SpeechBehavior with
        member this.Say() = _humanSpeechBehavior.Say()

    interface IAttackBehavior with
        member x.Attack() = _flyBehavior.Attack()

type King() =
    inherit Character(new SwordBehavior(), new HumanSpeech())

type Troll() =
    inherit Character(new CudgelBehavior(), new Growl())