import { v4 } from 'uuid';

type UUID = string

function generateUuid(): UUID {
  return v4()
}

export {
  type UUID,
  generateUuid,
}
