enum class Direction {
   X,
   Y,
   Z
};
namespace transformationRate {
   const float ROTATION_RATE = 1.1f;
   const float SCALING_RATE = 0.1f;
   const float TRANSLATION_RATE = 0.3f;

   static glm::vec3 rotationAngle(0.0f, 0.0f, 0.0f);
   static glm::vec3 translationVec(0.0f, 0.0f, 0.0f);
   static glm::vec3 scalingVec(1.0f, 1.0f, 1.0f);

   static void increaseRotationRate(Direction direction) {
      switch (direction){
         case (Direction::X):
            rotationAngle.x += ROTATION_RATE;
         break;
         case (Direction::Y):
            rotationAngle.y += ROTATION_RATE;
         break;
         case (Direction::Z):
            rotationAngle.z += ROTATION_RATE;
         break;
      }
   }
   static void decreaseRotationRate(Direction direction) {
      switch (direction){
         case (Direction::X):
            rotationAngle.x -= ROTATION_RATE;
         break;
         case (Direction::Y):
            rotationAngle.y -= ROTATION_RATE;
         break;
         case (Direction::Z):
            rotationAngle.z -= ROTATION_RATE;
         break;
      }
   }

   static void increaseScaling(Direction direction) {
      switch (direction){
         case (Direction::X):
            scalingVec.x += SCALING_RATE;
         break;
         case (Direction::Y):
            scalingVec.y += SCALING_RATE;
         break;
         case (Direction::Z):
            scalingVec.z += SCALING_RATE;
         break;
      }
   }
   static void decreaseScaling(Direction direction) {
      switch (direction){
         case (Direction::X):
            scalingVec.x -= SCALING_RATE;
         break;
         case (Direction::Y):
            scalingVec.y -= SCALING_RATE;
         break;
         case (Direction::Z):
            scalingVec.z -= SCALING_RATE;
         break;
      }
   }

   static void increaseTranslation(Direction direction) {
      switch (direction){
         case (Direction::X):
            translationVec.x += TRANSLATION_RATE;
         break;
         case (Direction::Y):
            translationVec.y += TRANSLATION_RATE;
         break;
         case (Direction::Z):
            translationVec.z += TRANSLATION_RATE;
         break;
      }
   }
   static void decreaseTranslation(Direction direction) {
      switch (direction){
         case (Direction::X):
            translationVec.x -= TRANSLATION_RATE;
         break;
         case (Direction::Y):
            translationVec.y -= TRANSLATION_RATE;
         break;
         case (Direction::Z):
            translationVec.z -= TRANSLATION_RATE;
         break;
      }
   }

   static void resetAll() {
      rotationAngle = glm::vec3(0.0f, 0.0f, 0.0f);
      translationVec = glm::vec3(0.0f, 0.0f, 0.0f);
      scalingVec = glm::vec3(1.0f, 1.0f, 1.0f);
   }
}
