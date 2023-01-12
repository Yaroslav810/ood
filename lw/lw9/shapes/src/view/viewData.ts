import {IShape} from "../model/domain/Shape";
import {UUID} from "../common/uuid/uuid";
import {Controller} from "../model/application/Controller";
import {Dispatch, SetStateAction} from "react";

interface ViewData {
    shapes: IShape[],
    controller: Controller,
    selectedUuid: UUID | null,
    setSelectedUuid: Dispatch<SetStateAction<UUID | null>>,
}

export {
    type ViewData,
}
