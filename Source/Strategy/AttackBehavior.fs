namespace Strategy

type IAttackBehavior =
    abstract Attack : unit -> unit

type SwordBehavior() =
    member this.Attack() = (this :> IAttackBehavior).Attack()
    interface IAttackBehavior with
        member this.Attack() = printfn "~Sword attack"

type CudgelBehavior() =
    member this.Attack() = (this :> IAttackBehavior).Attack()
    interface IAttackBehavior with
        member x.Attack() = printfn "~Cudgel attack"