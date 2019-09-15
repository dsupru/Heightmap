enum class Direction {
   X,
   Y,
   Z
};
namespace transformationRate {
   static glm::vec3 rotationAngle(0.0f, 0.0f, 0.0f);
   static glm::vec3 translationVec(0.0f, 0.0f, 0.0f);
   static glm::vec3 scalingVec(1.0f, 1.0f, 1.0f);

   static void increaseRotationRate(Direction direction) {
      switch (direction){
         case (Direction::X):
            rotationAngle.x += 1.1f;
         break;
         case (Direction::Y):
            rotationAngle.y += 1.1f;
         break;
         case (Direction::Z):
            rotationAngle.z += 1.1f;
         break;
      }
   }
   static void decreaseRotationRate(Direction direction) {
      switch (direction){
         case (Direction::X):
            rotationAngle.x -= 1.1f;
         break;
         case (Direction::Y):
            rotationAngle.y -= 1.1f;
         break;
         case (Direction::Z):
            rotationAngle.z -= 1.1f;
         break;
      }
   }

   static void increaseScaling(Direction direction) {
      switch (direction){
         case (Direction::X):
            scalingVec.x += 0.1f;
         break;
         case (Direction::Y):
            scalingVec.y += 0.1f;
         break;
         case (Direction::Z):
            scalingVec.z += 0.1f;
         break;
      }
   }
   static void decreaseScaling(Direction direction) {
      switch (direction){
         case (Direction::X):
            scalingVec.x -= 0.1f;
         break;
         case (Direction::Y):
            scalingVec.y -= 0.1f;
         break;
         case (Direction::Z):
            scalingVec.z -= 0.1f;
         break;
      }
   }

   static void increaseTranslation(Direction direction) {
      switch (direction){
         case (Direction::X):
            translationVec.x += 1.1f;
         break;
         case (Direction::Y):
            translationVec.y += 1.1f;
         break;
         case (Direction::Z):
            translationVec.z += 1.1f;
         break;
      }
   }
   static void decreaseTranslation(Direction direction) {
      switch (direction){
         case (Direction::X):
            translationVec.x -= 1.1f;
         break;
         case (Direction::Y):
            translationVec.y -= 1.1f;
         break;
         case (Direction::Z):
            translationVec.z -= 1.1f;
         break;
      }
   }

   static void resetAll() {
      rotationAngle = glm::vec3(0.0f, 0.0f, 0.0f);
      translationVec = glm::vec3(0.0f, 0.0f, 0.0f);
      scalingVec = glm::vec3(1.0f, 1.0f, 1.0f);
   }
}
