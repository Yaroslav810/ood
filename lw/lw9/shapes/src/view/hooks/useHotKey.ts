import {useCallback, useEffect} from "react"
import {UUID} from "../../common/uuid/uuid";
import {Controller} from "../../model/application/Controller";

function useHotKey(
    controller: Controller,
    selectItem: UUID | null,
) {
  const handleDel = useCallback((event: KeyboardEvent) => {
    if (event.key === 'Delete' && selectItem) {
      controller.deleteShape(selectItem)
    }
    if (event.ctrlKey) {
      if (event.code === 'KeyZ') {
        controller.undo()
      }
      if (event.code === 'KeyY') {
        controller.redo()
      }
    }
  }, [selectItem, controller])

  useEffect(() => {
    document.addEventListener('keydown', handleDel)
    return () => document.removeEventListener('keydown', handleDel)
  })
}

export {
  useHotKey,
}
